package nativewindowlib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public final class WindowUtils {

	/**
	 * https://stackoverflow.com/questions/3188484/windows-how-to-get-a-list-of-
	 * all-visible-windows
	 * 
	 * https://stackoverflow.com/questions/7521693/converting-c-sharp-to-java-
	 * jna-getmodulefilename-from-hwnd
	 */
	public static synchronized List<NativeWindow> getWindows() {
		final List<NativeWindow> inflList = new ArrayList<NativeWindow>();
		final List<Integer> order = new ArrayList<Integer>();

		int top = GetTopWindow(0);

		while (top != 0) {
			order.add(top);
			top = GetWindow(top, GW_HWNDNEXT);
			inflList.add(new NativeWindow(top));
		}

		try {
			enumWindows();

			Thread.sleep(Long.MAX_VALUE);
		} catch (InterruptedException e) {

		}
		
		for (int i : hwnds) {
			inflList.add(new NativeWindow(i));
		}

		hwnds.clear();

		Collections.sort(inflList, new Comparator<NativeWindow>() {
			public int compare(NativeWindow o1, NativeWindow o2) {
				return order.indexOf(o1.getHwnd()) - order.indexOf(o2.getHwnd());
			}
		});

		return inflList;
	}

	private static final List<Integer> hwnds = new ArrayList<Integer>();
	
	private static void callback(int i) {
		hwnds.add(i);

		if (i == -1) {
			Thread.currentThread().interrupt();
		}
	}
	
	private static native void enumWindows();

	/**
	 * Returns the current selected window
	 * 
	 * @return
	 */
	public static NativeWindow getActiveWindow() {
		return new NativeWindow(GetForegroundWindow());
	}

	/**
	 * Finds all windows and checks which are visible
	 * 
	 * @return all visible windows.
	 */
	public static List<NativeWindow> getVisibleWindows() {
		List<NativeWindow> visible = new ArrayList<NativeWindow>();
		List<NativeWindow> windows = WindowUtils.getWindows();

		for (NativeWindow w : windows) {
			if (w.isVisible() && w.getTitle() != null &&  w.getTitle().trim().length() > 0) {
				visible.add(w);
			}
		}

		return visible;
	}

	/**
	 * Finds all windows and searches for a matching title
	 * 
	 * @param title
	 *            the title to search for
	 * @return the window with the title that has been searched for, or null if
	 *         not found.
	 */
	public static NativeWindow getByTitle(String title) {
		return new NativeWindow(FindWindowA(null, title));
	}

	/**
	 * Prevent instantiation
	 */
	private WindowUtils() {
	}

	public static native boolean callback(int hWnd, int lParam);

	public static final int GW_HWNDNEXT = 2;

	/**
	 * Enumerate all native windows
	 * 
	 * @param wndenumproc
	 * @param lParam
	 * @return
	 */
	public static native boolean EnumWindows(int wndenumproc, int lParam); // TODO

	public static native int FindWindowA(String lpClassName, String lpWindowName);

	/**
	 * Is window visible (only show windows that is)
	 * 
	 * @param hWnd
	 * @return
	 */
	public static native boolean IsWindowVisible(int hWnd);

	/**
	 * Gets window position
	 * 
	 * @param hWnd
	 * @param r
	 * @return
	 */
	public static native int GetWindowRect(int hWnd, /*nativerectangle*/ int r);

	/**
	 * Moves window position
	 * 
	 * @param hWnd
	 * @param X
	 * @param Y
	 * @param nWidth
	 * @param nHeight
	 * @param bRepaint
	 * @return
	 */
	public static native boolean MoveWindow(int hWnd, int X, int Y, int nWidth, int nHeight, boolean bRepaint);

	/**
	 * Gets window title
	 * 
	 * @param hWnd
	 * @param buffer
	 * @param buflen
	 */
	public static native String GetWindowText(int hWnd);

	/**
	 * Sets window title
	 * 
	 * @param hWnd
	 * @param text
	 * @return
	 */
	public static native boolean SetWindowTextA(int hWnd, String text);

	public static native int GetWindowThreadProcessId(int hWnd);

	/**
	 * Gets window on top
	 * 
	 * @param hWnd
	 * @return
	 */
	public static native int GetTopWindow(int hWnd);

	public static native int GetWindow(int hWnd, int flag);

	/**
	 * Set focus on window
	 * 
	 * @param hWnd
	 * @return
	 */
	public static native boolean SetForegroundWindow(int hWnd);

	public static native int GetWindowThreadProcessId(int hWnd, /*intbyreference*/ int pid);

	/**
	 * Minimizes the window
	 * 
	 * @param hWnd
	 * @return
	 */
	public static native boolean CloseWindow(int hWnd);

	/**
	 * Closes the window
	 * 
	 * @param hWnd
	 * @return
	 */
	public static native boolean DestroyWindow(int hWnd);

	/**
	 * Changes state of the window
	 * 
	 * @param hWnd
	 * @param nCmdShow
	 * @return
	 */
	public static native boolean ShowWindow(int hWnd, int nCmdShow);

	/**
	 * Returns the current Window HWND
	 * 
	 * @return
	 */
	public static native int GetForegroundWindow();


	public static native String getProcessFromWindow(int hwnd);


/*	public static class NativeRectangle extends Structure {

		public int left;
		public int right;
		public int top;
		public int bottom;

		@Override
		protected List<String> getFieldOrder() {
			List<String> list = new ArrayList<String>();
			list.add("left");
			list.add("top");

			list.add("right");
			list.add("bottom");

			return list;
		}
	}*/
}