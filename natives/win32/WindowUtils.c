#include <windows.h>
#include <psapi.h>
#include <jni.h>

#include "../nativewindowlib_WindowUtils.h"
#include "../util.h"

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtil_showWindow(JNIEnv * env, jclass z, jint handle, jint mode) {
	HWND hwnd = (HWND) handle;

	ShowWindow(hwnd, mode);
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getTopWindow(JNIEnv * env, jclass z, jint handle) {
	return GetTopWindow(handle);
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getWindow(JNIEnv * env, jclass z, jint handle, jint mode) {
	return GetWindow(handle, mode);
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_isWindowVisible(JNIEnv * env, jclass z, jint handle) {
	return IsWindowVisible(handle);
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getWindowText(JNIEnv * env, jclass z, jint handle) {
	HWND hwnd = (HWND) handle;
	if (hwnd <= 0) {
		return getstring(env, "");
	}

	int length = GetWindowTextLengthA(handle);
	if (length <= 0) {
		return getstring(env, "");
	}

	LPSTR buffer = (LPSTR) malloc(length * sizeof(TCHAR));
	GetWindowTextA(hwnd, buffer, length + 1);
	jstring title = getstring(env, buffer);
	free(buffer);

	return title;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setWindowText(JNIEnv * env, jclass z, jint handle, jstring title) {
	SetWindowTextA(handle, getcstring(env, title));
}

static BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM LPARAM) {
	JNIEnv *env = (JNIEnv *) LPARAM;

	jmethodID method;
	jclass cls;

	cls = (*env)->FindClass(env, "nativewindowlib/WindowUtils");

	method = (*env)->GetStaticMethodID(env, cls, "callback", "(I)V");

	(*env)->CallStaticVoidMethod(env, cls, method, (int) handle);

	return TRUE;
}

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows(JNIEnv * env, jclass z) {
	EnumWindows(EnumWindowsCallback, env);
	EnumWindowsCallback(nativewindowlib_WindowUtils_CALLBACK_COMPLETED, env);
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getProcessFromWindow(JNIEnv * env, jclass z, jint handle) {
	HWND hwnd = (HWND) handle;

	LPSTR buffer = (LPSTR) malloc(MAX_PATH * sizeof(TCHAR));
	DWORD processId;
	GetWindowThreadProcessId(hwnd, &processId);
	HANDLE hndl = OpenProcess(1040, FALSE, processId);
	GetModuleFileNameExA(hndl, 0, buffer, MAX_PATH);
	jstring process = getstring(env, buffer);
	free(buffer);

	return process;
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getFromTitle(JNIEnv * env, jclass z, jstring title) {
	return FindWindowA(NULL, getcstring(env, title));
}

JNIEXPORT jobject JNICALL Java_nativewindowlib_WindowUtils_getWindowRect(JNIEnv * env, jclass z, jint handle) {
	HWND hwnd = (HWND) handle;
	if (hwnd == 0) {
		return NULL;
	}

	RECT rect;
	GetWindowRect(handle, &rect);

	jclass clazz = (*env)->FindClass(env, "java/awt/Rectangle");
	jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(IIII)V");

	int x = rect.left;
	int y = rect.top;
	int width = rect.right - x;
	int height = rect.bottom - y;

	jobject rectangle = (*env)->NewObject(env, clazz, constructor, x, y, width, height);
	return rectangle;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_moveWindow(JNIEnv * env, jclass z, jint handle, jint x, jint y, jint width, jint height) {
	return MoveWindow(handle, x, y, width, height, TRUE);
}
