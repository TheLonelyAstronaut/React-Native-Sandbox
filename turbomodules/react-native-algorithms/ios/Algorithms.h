#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@class NativeDijkstra;

@interface Algorithms : NSObject <RCTBridgeModule>

@property (nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
