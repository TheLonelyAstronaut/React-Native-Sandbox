package com.reactnativealgorithms

import android.util.Log
import com.facebook.react.bridge.*
import com.facebook.react.module.annotations.ReactModule

class AlgorithmsModule(reactContext: ReactApplicationContext?) : ReactContextBaseJavaModule(reactContext) {
  override fun getName(): String {
    return "Algorithms"
  }

  companion object {
    external fun initializeNativeAlgorithmsModule(jsiPointer: Long)
    external fun clearNativeAlgorithmsModule()

    init {
      try {
        System.loadLibrary("algorithms")
      } catch (ignored: Exception) {

      }
    }

    fun install(jsContext: JavaScriptContextHolder?) {
      Log.e("ERROR TEST TAG", "INSTALLING JSI MODULE")
      Log.d("JSC", jsContext?.get().toString())

      val internalJsContext = jsContext?.get()

      if(internalJsContext != null) {
        initializeNativeAlgorithmsModule(internalJsContext)
      }
    }
  }

  override fun onCatalystInstanceDestroy() {
    clearNativeAlgorithmsModule()
  }
}
