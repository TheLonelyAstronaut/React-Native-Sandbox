#include <jni.h>
#include "algorithms_core.hpp"

using namespace facebook;

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_initializeNativeAlgorithmsModule(JNIEnv *env, jclass type, jlong jsiPtr) {
    AlgorithmsCore::initialize(*reinterpret_cast<jsi::Runtime *>(jsiPtr));
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_clearNativeAlgorithmsModule(JNIEnv *env, jclass type) {
    AlgorithmsCore::clear();
}
