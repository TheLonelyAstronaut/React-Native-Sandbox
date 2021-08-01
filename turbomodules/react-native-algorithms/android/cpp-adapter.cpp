#include <jni.h>
#include "algorithms_core.hpp"

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
    return example::multiply(a, b);
}
