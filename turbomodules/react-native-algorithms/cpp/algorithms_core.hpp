#ifndef ALGORITHMS_CORE_H
#define ALGORITHMS_CORE_H

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

#include <iostream>
#include <memory>
#include <type_traits>

#include "dijkstra/dijkstra_algorithm.h"

#ifdef ON_ANDROID
#include <jni.h>
#endif

using namespace facebook;

class AlgorithmsCore {
    static std::shared_ptr<AlgorithmsCore> _object;

    std::shared_ptr<jsi::Runtime> _jsiRuntime;
    std::shared_ptr<DijkstraAlgorithm> _dijkstra;

    #ifdef ON_ANDROID
    std::shared_ptr<JNIEnv> _nativeInterface;
    jclass type;
    #endif

    AlgorithmsCore() = delete;
    AlgorithmsCore(jsi::Runtime &jsiRuntime);
public:
    static void initialize(jsi::Runtime &jsiRuntime);

    #ifdef ON_ANDROID
    void setJNIEnv(JNIEnv *jniEnv);
    #endif

    static void clean();
    static void getShortestGraphPath();
}

#endif
