#include "engine.h"

#include "runtime/function/global_context.h"

namespace ToyEngine {

  void ToyEngine::startEngine() {

    g_runtime_global_context.startSystems(std::string(""));
  }


  void ToyEngine::shutdownEngine() {

  }

  void ToyEngine::initialize() {
  }

  void ToyEngine::clear() {

  }


  void ToyEngine::run() {

    while (1) {
    
    }
  }

}