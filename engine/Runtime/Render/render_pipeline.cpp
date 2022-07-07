#include "runtime/render/render_pipeline.h"

#include "runtime/render/ui_pass.h"


namespace ToyEngine
{
    void RenderPipeline::initialize(RenderPipelineInitInfo init_info)
    {
        m_ui_pass = std::make_shared<UIPass>();

        UIPassInitInfo ui_init_info;
        //ui_init_info.render_pass = _main_camera_pass->getRenderPass();
        m_ui_pass->initialize(&ui_init_info);

    }

    void RenderPipeline::forwardRender(/*std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource*/)
    {
        
    }

    void RenderPipeline::deferredRender(/*std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource*/)
    {
        
    }

    void RenderPipeline::passUpdateAfterRecreateSwapchain()
    {
       
    }
    uint32_t RenderPipeline::getGuidOfPickedMesh(const Vector2& picked_uv)
    {
      /*  PickPass& pick_pass = *(static_cast<PickPass*>(m_pick_pass.get()));
        return pick_pass.pick(picked_uv);*/
      return 0;
    }

  /* u void RenderPipeline::setAxisVisibleState(bool state)
    {
        MainCameraPass& main_camera_pass = *(static_cast<MainCameraPass*>(m_main_camera_pass.get()));
        main_camera_pass.m_is_show_axis  = state;
    }

    void RenderPipeline::setSelectedAxis(size_t selected_axis)
    {
        MainCameraPass& main_camera_pass = *(static_cast<MainCameraPass*>(m_main_camera_pass.get()));
        main_camera_pass.m_selected_axis = selected_axis;
    }*/
} // namespace ToyEngine
