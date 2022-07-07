#include "editor.h"
#include <windows.h>
//#include "runtime/render/render_system.h"
#include "runtime/function/global_context.h"

namespace ToyEngine {

	ToyEditor::ToyEditor() {}
	ToyEditor::~ToyEditor() {}

	void ToyEditor::initialize(ToyEngine *engineRuntime) {
    m_EngineRuntime = engineRuntime;

		m_editor_ui = std::make_shared<EditorUI>();
		WindowUIInitInfo ui_init_info = { g_runtime_global_context.m_window_system,
																		  g_runtime_global_context.m_render_system };
		m_editor_ui->initialize(ui_init_info);
	}

	void ToyEditor::clear() {}


	void ToyEditor::run() {
		while(1) {
			//assert(m_engine_runtime);
			//assert(m_editor_ui);
			//float delta_time;
			//while (true)
			//{
			//	delta_time = m_engine_runtime->calculateDeltaTime();
			//	g_editor_global_context.m_scene_manager->tick(delta_time);
			//	g_editor_global_context.m_input_manager->tick(delta_time);
			//	if (!m_engine_runtime->tickOneFrame(delta_time))
			//		return;
			//}
			Sleep(1000);
		}
	}

}