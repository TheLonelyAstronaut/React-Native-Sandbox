//
// Created by Vadzim Filipovich on 8/12/21.
//

#include "AlgorithmsExtension.h"
#include "../../../../cpp/algorithms_core.h"

std::shared_ptr<JavaVM> AlgorithmsExtension::javaVM;

void AlgorithmsExtension::initialize(JNIEnv *env, jlong jsiPtr) {
    auto runtime = reinterpret_cast<jsi::Runtime *>(jsiPtr);

    JavaVM* temporaryPtr;
    env->GetJavaVM(&temporaryPtr);

    AlgorithmsExtension::javaVM.reset(temporaryPtr);

    if(runtime) {
        AlgorithmsCore::setDijkstraAlgorithmResolver([]() {
            std::shared_ptr<JNIEnv> currentEnv;

            AlgorithmsExtension::javaVM->GetEnv(reinterpret_cast<void**>(&currentEnv), JNI_VERSION_1_6);

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
