#pragma once

#include <memory>
#include "..\engine\engine.h"

namespace ToyEngine {
class ToyEngine;

class ToyEditor {

public:
  ToyEditor();
  virtual ~ToyEditor();

  void initialize(ToyEngine *engine_runtime);
  void clear();

  void run();

protected:
  ToyEngine * m_EngineRuntime = NULL;
};
} // namespace Pilot
