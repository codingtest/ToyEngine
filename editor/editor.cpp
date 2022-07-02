#include "editor.h"


namespace ToyEngine {

	ToyEditor::ToyEditor() {}
	ToyEditor::~ToyEditor() {}

	void ToyEditor::initialize(ToyEngine *engineRuntime) {
    m_EngineRuntime = engineRuntime;

		m_editor_ui = std::make_shared<EditorUI>();
		WindowUIInitInfo ui_init_info = {  };
		m_editor_ui->initialize(ui_init_info);
	}

	void ToyEditor::clear() {}


	void ToyEditor::run() {
		while(1) {

		}
	}

}