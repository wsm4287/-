#include <jni.h>
#include <string>
#include <unistd.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_week11_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */, jint a) {
    std::string hello = "Hello from C++";
    syscall(323, a + a*100);
    return env->NewStringUTF(hello.c_str());
}