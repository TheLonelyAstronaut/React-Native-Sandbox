package com.reactnativealgorithms

import com.facebook.react.bridge.*

class AlgorithmsJSIModulePackage: JSIModulePackage {
  override fun getJSIModules(
    reactApplicationContext: ReactApplicationContext?,
    jsContext: JavaScriptContextHolder?
  ): MutableList<JSIModuleSpec<JSIModule>> {
    AlgorithmsModule.install(reactApplicationContext?.javaScriptContextHolder)

    return mutableListOf()
  }
}
