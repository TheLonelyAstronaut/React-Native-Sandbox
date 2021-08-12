#include <jni.h>
#include "algorithms_core.h"
#include <android/log.h>
#include <string>

using namespace facebook;

JavaVM* javaVM;

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_00024Companion_initializeNativeAlgorithmsModule(JNIEnv *env, jobject type, jlong jsiPtr) {
    auto runtime = reinterpret_cast<jsi::Runtime *>(jsiPtr);
    env->GetJavaVM(&javaVM);

    if(runtime) {
        AlgorithmsCore::setDijkstraAlgorithmResolver([]() {
            JNIEnv* currentEnv;

            javaVM->GetEnv(reinterpret_cast<void**>(&currentEnv), JNI_VERSION_1_6);

            auto kotlinDijkstra = currentEnv->FindClass("com/reactnativealgorithms/dijkstra/NativeDijkstra");

            auto constructor = currentEnv->GetMethodID(kotlinDijkstra, "<init>", "()V");
            auto object = currentEnv->NewObject(kotlinDijkstra, constructor);

            auto getShortestGraphPath = currentEnv->GetMethodID(kotlinDijkstra, "getShortestGraphPath", "()Ljava/lang/String;");

            auto result = reinterpret_cast<jstring>(currentEnv->CallObjectMethod(object, getShortestGraphPath));

            std::string stdResult = currentEnv->GetStringUTFChars(result, 0);

            return stdResult;
        });

        AlgorithmsCore::initialize(*runtime);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativealgorithms_AlgorithmsModule_00024Companion_clearNativeAlgorithmsModule(JNIEnv *env, jobject type) {
    AlgorithmsCore::clear();
}
