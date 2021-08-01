package com.reactnativealgorithms

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.module.annotations.ReactModule

@ReactModule(name = AlgorithmsModule.name)
class AlgorithmsModule(reactContext: ReactApplicationContext?) : ReactContextBaseJavaModule(reactContext) {

  companion object {
    @get:NonNull
    @get:Override
    val name = "Algorithms"

    external fun nativeMultiply(a: Int, b: Int): Int

    init {
      try {
        // Used to load the 'native-lib' library on application startup.
        System.loadLibrary("cpp")
      } catch (ignored: Exception) {
      }
    }
  }

  // Example method
  // See https://reactnative.dev/docs/native-modules-android
  @ReactMethod
  fun multiply(a: Int, b: Int, promise: Promise) {
    promise.resolve(nativeMultiply(a, b))
  }
}
