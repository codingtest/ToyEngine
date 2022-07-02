#pragma once

#include <memory>
#include "..\engine\engine.h"
#include "editor_ui.h"

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
  std::shared_ptr<EditorUI> m_editor_ui;
  ToyEngine * m_EngineRuntime = NULL;
};
} // namespace Pilot
