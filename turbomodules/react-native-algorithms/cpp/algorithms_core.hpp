#ifndef ALGORITHMS_CORE_H
#define ALGORITHMS_CORE_H

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

using namespace facebook;

namespace AlgorithmsCore {
  void initialize(jsi::Runtime& jsiRuntime);
  void clean();
}

#endif /* EXAMPLE_H */
