import React, { useRef, useMemo, useCallback, useState } from 'react';
import {
    Text,
    View,
    StyleSheet,
    ImageBackground,
    Dimensions,
} from 'react-native';
import BottomSheet from '@gorhom/bottom-sheet';
import {
    PanGestureHandler,
    PanGestureHandlerGestureEvent,
} from 'react-native-gesture-handler';
import Animated, {
    runOnJS,
    useAnimatedGestureHandler,
    useAnimatedStyle,
    useSharedValue,
    withTiming,
} from 'react-native-reanimated';

const AnimatedImageBackground =
    Animated.createAnimatedComponent(ImageBackground);

const SCREEN_WIDTH = Dimensions.get('window').width;
const LEFT_THRESHOLD = SCREEN_WIDTH / 3;
const ROTATION_MAX_DEGREE = 20;
const MAX_AVAILABLE_ROTATION = 45;
const MAX_AVAILABLE_SHEET_HIDING_DELTA = 100;

export const getRotateAngle = (translationX: number): number => {
    'worklet';
    const margin = 70 - Math.abs(translationX);

    if (margin < 0) {
        return translationX < 0
            ? (+(translationX + 70) * ROTATION_MAX_DEGREE) / LEFT_THRESHOLD
            : (+(translationX - 70) * ROTATION_MAX_DEGREE) / LEFT_THRESHOLD;
    } else {
        return withTiming(0);
    }
};

export const getTranslationX = (angle: number): number => {
    'worklet';
    const multiplier = angle / MAX_AVAILABLE_ROTATION;

    return multiplier * SCREEN_WIDTH;
};

export const getTranslationY = (angle: number): number => {
    'worklet';
    const multiplier = angle / MAX_AVAILABLE_ROTATION;

    return Math.abs(multiplier) * MAX_AVAILABLE_SHEET_HIDING_DELTA;
};

export const App: React.FC = () => {
    const panRef = useRef<PanGestureHandler>();
    const [mounted, setMounted] = useState(false);
    const bottomSheetRef = useRef<BottomSheet>(null);
    const snapPoints = useMemo(() => ['25%', '50%', '100%'], []);

    const rotate = useSharedValue(0);
    const translateX = useSharedValue(0);
    const translateY = useSharedValue(0);
    const reaction = useSharedValue(-1);

    const test = useCallback(() => {
        bottomSheetRef.current?.close();
    }, []);

    const test2 = useCallback(() => {
        translateY.value = 0;
        translateX.value = 0;
        rotate.value = 0;
        bottomSheetRef.current?.snapToIndex(1);
    }, [translateX, translateY, rotate, bottomSheetRef]);

    const handleSheetChanges = useCallback(
        (index: number) => {
            if (index === -1) {
                test2();
            }
        },
        [test2]
    );

    const gestureHandler = useAnimatedGestureHandler<
        PanGestureHandlerGestureEvent,
        { posX: number; posY: number; delta: number }
    >(
        {
            onStart: (event, ctx) => {
                ctx.posX = 0;
                ctx.posY = 0;
                ctx.delta = 70;
            },
            onActive: (event) => {
                rotate.value = getRotateAngle(event.translationX);
                translateX.value = getTranslationX(rotate.value);
                translateY.value = getTranslationY(rotate.value);

                console.log(rotate.value);
            },
            onFinish: () => {
                if (Math.abs(rotate.value) > ROTATION_MAX_DEGREE * 1.2) {
                    rotate.value = withTiming(rotate.value > 0 ? 90 : -90);

                    if (rotate.value > 0) {
                        reaction.value = 1;
                    } else {
                        reaction.value = 0;
                    }

                    runOnJS(test)();
                } else {
                    rotate.value = withTiming(0);
                    translateX.value = withTiming(0);
                    translateY.value = withTiming(0);
                }
            },
        },
        [test]
    );

    const animatedStyle = useAnimatedStyle(() => {
        return {
            flex: 1,
            transform: [
                {
                    rotate: `${rotate.value}deg`,
                },
                {
                    translateX: translateX.value,
                },
                {
                    translateY: translateY.value,
                },
            ],
        };
    });

    return (
        <PanGestureHandler
            ref={panRef}
            onGestureEvent={gestureHandler}
            simultaneousHandlers={bottomSheetRef.current?.internalPanRef}
        >
            <AnimatedImageBackground
                source={require('./assets/babe.png')}
                style={{ flex: 1 }}
                onLayout={() => setMounted(true)}
            >
                {mounted && (
                    <Animated.View style={animatedStyle}>
                        <BottomSheet
                            enablePanDownToClose
                            ref={bottomSheetRef}
                            simultaneousHandlers={panRef}
                            index={1}
                            snapPoints={snapPoints}
                            onChange={handleSheetChanges}
                        >
                            <View style={styles.contentContainer}>
                                <Text>Awesome 🎉</Text>
                            </View>
                        </BottomSheet>
                    </Animated.View>
                )}
            </AnimatedImageBackground>
        </PanGestureHandler>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        padding: 24,
        backgroundColor: 'grey',
    },
    contentContainer: {
        flex: 1,
        alignItems: 'center',
        backgroundColor: 'blue',
    },
});
