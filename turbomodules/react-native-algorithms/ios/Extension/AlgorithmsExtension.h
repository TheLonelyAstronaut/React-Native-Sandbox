//
//  AlgorithmsExtension.h
//  Pods
//
//  Created by Vadzim Filipovich on 8/12/21.
//

#ifndef AlgorithmsExtension_h
#define AlgorithmsExtension_h

#import "algorithms_core.h"
#import "react_native_algorithms-Swift.h"

class AlgorithmsExtension {
    static NativeDijkstra *_dijkstra;
public:
    static void initialize(jsi::Runtime &jsiRuntime);
};

#endif /* AlgorithmsExtension_h */
