//
//  AlgorithmsExtension.m
//  react-native-algorithms
//
//  Created by Vadzim Filipovich on 8/12/21.
//

#import <Foundation/Foundation.h>
#import "AlgorithmsExtension.h"
#import <string>

NativeDijkstra* AlgorithmsExtension::_dijkstra = [[NativeDijkstra alloc] init];

void AlgorithmsExtension::initialize(jsi::Runtime &jsiRuntime) {
    
    AlgorithmsCore::setDijkstraAlgorithmResolver([]() {
        NSString *str = [AlgorithmsExtension::_dijkstra getShortestGraphPath];
        
        return std::string([str UTF8String]);
    });
    
    AlgorithmsCore::initialize(jsiRuntime);
}
