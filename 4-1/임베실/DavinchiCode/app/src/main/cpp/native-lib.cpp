#include <jni.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>

#define CMD_PUT		3
#define CMD_GET		4

struct ioctl_env {
    int key[4];
    int value[1024];
};

extern "C"
JNIEXPORT void JNICALL
Java_com_example_davinchicode_Game_segment(JNIEnv *env, jobject thiz, jint a) {
    // TODO: implement segment()
    syscall(323, a);
    return;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_davinchicode_Game_led(JNIEnv *env, jobject thiz, jint a) {
    // TODO: implement segment()
    syscall(324, a);
    return;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_davinchicode_Game_read(JNIEnv *env, jobject thiz, jintArray buf) {
    // TODO: implement segment()
    struct ioctl_env a;
    int size = env->GetArrayLength(buf);
    jint *bbuf;
    bbuf = (jint*)malloc(sizeof(jint)*size);

    for(int i=0; i<4; i++) a.key[i] = 0;
    syscall(325, CMD_GET, &a);

    for(int i=0; i<1024; i++){
        bbuf[i] = a.value[i];
    }

    env->SetIntArrayRegion(buf, 0, size, (const jint *)bbuf);
    free(bbuf);



    return;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_davinchicode_Game_write(JNIEnv *env, jobject thiz, jintArray buf) {
// TODO: implement segment()
    struct ioctl_env a;
    jint *bbuf;
    bbuf = env->GetIntArrayElements(buf, NULL);
    for(int i=0; i<4; i++) a.key[i] = 0;
    for(int i=0; i<1024; i++) a.value[i] = bbuf[i];
    syscall(325, CMD_PUT, &a);

    env->ReleaseIntArrayElements(buf, bbuf, 0);

    //env->ReleaseIntArrayElements(buf, bbuf, 0);
    return;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_davinchicode_MainActivity_start(JNIEnv *env, jobject thiz) {
    // TODO: implement start()
    syscall(323, 0);
    syscall(324, 0);
    return;
}

