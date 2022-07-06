#pragma once

//#include "runtime/function/render/render_pass.h"

#include <d3d12.h>
#include <dxgi1_4.h>

namespace ToyEngine
{
    class WindowUI;

    //struct UIPassInitInfo : RenderPassInitInfo
    //{
    //    //VkRenderPass render_pass;
    //};

    class UIPass /*: public RenderPass*/
    {
    public:
        void initialize(/*const RenderPassInitInfo* init_info*/)/* override final*/;
        void initializeUIRenderBackend(WindowUI* window_ui) /*override final*/;
        void draw() /*override final*/;

        bool CreateDeviceD3D(HWND hWnd);

        void CleanupDeviceD3D();

    private:
        WindowUI* m_window_ui;

        // Data
        int const                    NUM_FRAMES_IN_FLIGHT = 3;
        //FrameContext                 g_frameContext[NUM_FRAMES_IN_FLIGHT] = {};
        UINT                         g_frameIndex = 0;

        int const                    NUM_BACK_BUFFERS = 3;
         ID3D12Device* g_pd3dDevice = NULL;
         ID3D12DescriptorHeap* g_pd3dRtvDescHeap = NULL;
         ID3D12DescriptorHeap* g_pd3dSrvDescHeap = NULL;
         ID3D12CommandQueue* g_pd3dCommandQueue = NULL;
         ID3D12GraphicsCommandList* g_pd3dCommandList = NULL;
         ID3D12Fence* g_fence = NULL;
         HANDLE                       g_fenceEvent = NULL;
         UINT64                       g_fenceLastSignaledValue = 0;
         IDXGISwapChain3* g_pSwapChain = NULL;
         HANDLE                       g_hSwapChainWaitableObject = NULL;
        /* ID3D12Resource* g_mainRenderTargetResource[NUM_BACK_BUFFERS] = {};
         D3D12_CPU_DESCRIPTOR_HANDLE  g_mainRenderTargetDescriptor[NUM_BACK_BUFFERS] = {};*/

    };
} // namespace ToyEngine