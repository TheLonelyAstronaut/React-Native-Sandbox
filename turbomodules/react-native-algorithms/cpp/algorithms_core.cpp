#include "algorithms_core.hpp"

void AlgorithmsCore::initialize(jsi::Runtime &jsiRuntime) {
    AlgorithmsCore::_object = std::shared_ptr<AlgorithmsCore>(new AlgorithmsCore(jsiRuntime));
}

AlgorithmsCore::AlgorithmsCore(jsi::Runtime &jsiRuntime) {
    this->_jsiRuntime = std::shared_ptr<jsi::Runtime>(jsiRuntime);
    this->_dijkstra = std::make_shared<DijkstraAlgorithm>();
}

#ifdef ON_ANDROID
void AlgorithmsCore::setJNIEnv(JNIEnv *jniEnv) {
    this->_nativeInterface = std::shared_ptr(jniEnv);
}
#endif

void AlgorithmsCore::getShortestGraphPath() {
    AlgorithmsCore::_object->_dijkstra->getShortestGraphPath();
}

void AlgorithmsCore::clear() {
    AlgorithmsCore::_object.reset();
}