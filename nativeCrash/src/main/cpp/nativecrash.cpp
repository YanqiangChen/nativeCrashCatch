#include <jni.h>
#include <string>
#include <android/log.h>
#include "client/linux/handler/minidump_descriptor.h"
#include "client/linux/handler/exception_handler.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativecrash_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativecrash_NativeLib_testNativeCrash(JNIEnv *env, jclass clazz) {
    // TODO: implement testNativeCrash()
    volatile int* a = reinterpret_cast<volatile int*>(NULL);
    *a = 1;

}

bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor,
                  void *context,
                  bool succeeded) {
    return false;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativecrash_NativeLib_initBreakPad(JNIEnv *env, jclass clazz, jstring path_) {
    // TODO: implement initBreakPad()
    const char *path = env->GetStringUTFChars(path_, 0);
    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback,NULL, true, -1);
    env->ReleaseStringUTFChars(path_, path);

}