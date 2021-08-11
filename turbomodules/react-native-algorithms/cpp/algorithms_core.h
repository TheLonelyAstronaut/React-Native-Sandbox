#ifndef ALGORITHMS_CORE_H
#define ALGORITHMS_CORE_H

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

#include <iostream>
#include <memory>
#include <type_traits>

#ifdef ON_ANDROID
#include <jni.h>
#endif

using namespace facebook;

typedef std::function<std::string()> DijkstraAlgorithm;

class AlgorithmsCore {
    static DijkstraAlgorithm _dijkstra;

    #ifdef ON_ANDROID
    static std::unique_ptr<JNIEnv> _nativeInterface;
    static jclass type;
    #endif

public:
    static void initialize(jsi::Runtime &jsiRuntime);

    #ifdef ON_ANDROID
    static void setJNIEnv(JNIEnv *jniEnv);
    #endif

    static void setDijkstraAlgorithmResolver(const DijkstraAlgorithm &algorithm);
    static void getShortestGraphPath();

    static void clear();
};

#endif
