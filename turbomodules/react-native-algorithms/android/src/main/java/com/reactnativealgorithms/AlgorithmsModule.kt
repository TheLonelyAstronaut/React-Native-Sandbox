package com.reactnativealgorithms

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.module.annotations.ReactModule

@ReactModule(name = AlgorithmsModule.name)
class AlgorithmsModule(reactContext: ReactApplicationContext?) : ReactContextBaseJavaModule(reactContext) {

  companion object {
    override val name = "Algorithms"

    external fun initializeNativeAlgorithmsModule(jsiPointer: Long): Unit
    external fun clearNativeAlgorithmsModule(): Unit

    init {
      try {
        System.loadLibrary("algorithms")
      } catch (ignored: Exception) {

      }
    }
  }

  override fun initialize() {
    super.initialize()

    initializeNativeAlgorithmsModule(
      AlgorithmsModule.getReactApplicationContext().getJavaScriptContextHolder().get()
    )
  }

  override fun onCatalystInstanceDestroy() {
    AlgorithmsModule.clearNativeAlgorithmsModule()
  }
}
