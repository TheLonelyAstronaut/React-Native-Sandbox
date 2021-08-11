#import "Algorithms.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import "AlgorithmsExtension.h"
//#import "react_native_algorithms-Swift.h"

@implementation Algorithms

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
    return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    _setBridgeOnMainQueue = RCTIsMainQueue();

    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
    
    if (!cxxBridge.runtime) {
      return;
    }
  
    AlgorithmsExtension::initialize(*(jsi::Runtime *)cxxBridge.runtime);
    
    //NativeDijkstra *test = [[NativeDijkstra alloc] init];
}

- (void)invalidate {
    AlgorithmsCore::clear();
}

@end
