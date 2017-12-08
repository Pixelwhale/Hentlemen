#pragma once
#include <DX\Include\DXGI.h>
#include <DX\Include\D3Dcommon.h>
#include <DX\Include\D3D11.h>
#include <DX\Include\D3DX10math.h>

namespace Core
{
	class DXGraphic
	{
	public:
		DXGraphic();
		DXGraphic(const DXGraphic&);
		~DXGraphic();

		bool Initialize(bool vsync, HWND hwnd);
		void Shutdown();

		void Begin(float, float, float, float);
		void End();

		ID3D11Device* GetDevice();
		ID3D11DeviceContext* GetDeviceContext();

		void GetProjectionMatrix(D3DXMATRIX&);
		void GetWorldMatrix(D3DXMATRIX&);
		void GetOrthoMatrix(D3DXMATRIX&);

		void GetVideoCardInfo(char*, int&);

	private:
		bool m_vsync_enabled;
		int m_videoCardMemory;
		char m_videoCardDescription[128];
		IDXGISwapChain* m_swapChain;
		ID3D11Device* m_device;								//Graphic Device
		ID3D11DeviceContext* m_deviceContext;
		ID3D11RenderTargetView* m_renderTargetView;			//Renderer Target
		ID3D11Texture2D* m_depthStencilBuffer;				//Depth Buffer
		ID3D11DepthStencilState* m_depthStencilState;		//Depth Stencil
		ID3D11DepthStencilView* m_depthStencilView;			//Depth Stencil
		ID3D11RasterizerState* m_rasterState;				//ラスタライズ

		D3DXMATRIX m_projectionMatrix;
		D3DXMATRIX m_worldMatrix;
		D3DXMATRIX m_orthoMatrix;
	};
}