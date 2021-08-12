#include <jni.h>
#include "algorithms_core.h"
#include "src/main/cpp/AlgorithmsExtension.h"
#include <android/log.h>
#include <memory>
#include <string>

using namespace facebook;

JavaVM* javaVM;

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_00024Companion_initializeNativeAlgorithmsModule(JNIEnv *env, jobject type, jlong jsiPtr) {
    AlgorithmsExtension::initialize(env, jsiPtr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_00024Companion_clearNativeAlgorithmsModule(JNIEnv *env, jobject type) {
    AlgorithmsCore::clear();
}
