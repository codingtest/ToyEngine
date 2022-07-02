#include <iostream>
#include <string>
#include <thread>

#include "..\engine/engine.h"
#include "editor_ui.h"


int main(int argc, char **argv) {

  ToyEngine::ToyEngine *engine = new ToyEngine::ToyEngine();

  engine->startEngine();
  engine->initialize();

  ToyEngine::ToyEditor *editor = new ToyEngine::ToyEditor();
  editor->initialize(engine);

  editor->run();

  editor->clear();

  engine->clear();
  engine->shutdownEngine();

  return 0;
}
