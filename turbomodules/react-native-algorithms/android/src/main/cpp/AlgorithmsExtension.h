//
// Created by Vadzim Filipovich on 8/12/21.
//

#ifndef ANDROID_ALGORITHMSEXTENSION_H
#define ANDROID_ALGORITHMSEXTENSION_H

#include <jni.h>
#include <memory>

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

using namespace facebook;

class AlgorithmsExtension {
    AlgorithmsExtension() = delete;
    static std::shared_ptr<JavaVM> javaVM;
public:
    static void initialize(JNIEnv *env, jlong jsiPtr);
};


#endif //ANDROID_ALGORITHMSEXTENSION_H
