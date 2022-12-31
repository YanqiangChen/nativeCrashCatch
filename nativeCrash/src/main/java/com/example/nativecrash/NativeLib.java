package com.example.nativecrash;

import android.content.Context;

import java.io.File;

public class NativeLib {

    // Used to load the 'nativecrash' library on application startup.
    static {
        System.loadLibrary("nativecrash");
    }

    public static void init(Context context) {
        File file = new File(context.getExternalCacheDir(), "breakPadTest");
        if (!file.exists()) {
            file.mkdirs();
        }
        initBreakPad(file.getAbsolutePath());

        testNativeCrash();
    }
    /**
     * A native method that is implemented by the 'nativecrash' native library,
     * which is packaged with this application.
     */
    public static native void testNativeCrash();
    public static native void initBreakPad(String path);
}