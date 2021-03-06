/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nativewindowlib_WindowUtils */

#ifndef _Included_nativewindowlib_WindowUtils
#define _Included_nativewindowlib_WindowUtils
#ifdef __cplusplus
extern "C" {
#endif
#undef nativewindowlib_WindowUtils_CALLBACK_COMPLETED
#define nativewindowlib_WindowUtils_CALLBACK_COMPLETED 0L
#undef nativewindowlib_WindowUtils_CALLBACK_FAILED
#define nativewindowlib_WindowUtils_CALLBACK_FAILED 1L
#undef nativewindowlib_WindowUtils_GW_HWNDNEXT
#define nativewindowlib_WindowUtils_GW_HWNDNEXT 2L
/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    enumWindows
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows
  (JNIEnv *, jclass);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getFromTitle
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getFromTitle
  (JNIEnv *, jclass, jstring);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    isWindowVisible
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_isWindowVisible
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getWindowRect
 * Signature: (I)Ljava/awt/Rectangle;
 */
JNIEXPORT jobject JNICALL Java_nativewindowlib_WindowUtils_getWindowRect
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    moveWindow
 * Signature: (IIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_moveWindow
  (JNIEnv *, jclass, jint, jint, jint, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getWindowText
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getWindowText
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    setWindowText
 * Signature: (ILjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setWindowText
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getTopWindow
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getTopWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getWindow
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getWindow
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    setForegroundWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setForegroundWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    minimizeWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_minimizeWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    isMinimized
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_isMinimized
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    closeWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_closeWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    showWindow
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_showWindow
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getForegroundWindow
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getForegroundWindow
  (JNIEnv *, jclass);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getProcessFromWindow
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getProcessFromWindow
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif
