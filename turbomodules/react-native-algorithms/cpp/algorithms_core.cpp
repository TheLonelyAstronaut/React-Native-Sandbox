#include "algorithms_core.h"
//#include "NativeDijkstra_CppExtension.h"

DijkstraAlgorithm AlgorithmsCore::_dijkstra;

#ifdef ON_ANDROID
static std::unique_ptr<JNIEnv> _nativeInterface;
static jclass type;
#endif

void AlgorithmsCore::initialize(jsi::Runtime &jsiRuntime) {
    auto propName = jsi::PropNameID::forAscii(jsiRuntime, "getShortestGraphPath");
    
    auto resolver = [](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) {
        printf("Shotrest graph path...");
        
        auto result = AlgorithmsCore::_dijkstra();
    
        return jsi::Value(runtime, jsi::String::createFromAscii(runtime, result.c_str()));
    };
    
    auto paramsCount = 0;
    
    auto getShortestGraphPath = jsi::Function::createFromHostFunction(jsiRuntime, propName, paramsCount, resolver);
    
    jsiRuntime.global().setProperty(jsiRuntime, "getShortestGraphPath", std::move(getShortestGraphPath));
}

#ifdef ON_ANDROID
void AlgorithmsCore::setJNIEnv(JNIEnv *jniEnv) {
    AlgorithmsCore::_nativeInterface = std::shared_ptr(jniEnv);
}
#endif

void AlgorithmsCore::setDijkstraAlgorithmResolver(const DijkstraAlgorithm &algorithm) {
    AlgorithmsCore::_dijkstra = algorithm;
}

void AlgorithmsCore::clear() {

}
