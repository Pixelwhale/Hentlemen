//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04～2017.12.09
// 内容　：DXのLibraryでまとめた描画関数
//-------------------------------------------------------
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

		/// <summary>初期化</summary>
		/// <param name="hwnd">Window Handle</param>
		bool Initialize(HWND hwnd);
		/// <summary>シャットダウン処理</summary>
		void Shutdown();

		/// <summary>ClearColor設定 描画開始</summary>
		/// <param name="r">Red</param>
		/// <param name="g">Green</param>
		/// <param name="b">Blue</param>
		/// <param name="a">Alpha</param>
		void Begin(float r, float g, float b, float a);
		/// <summary>Swap Buffer</summary>
		void End();

		/// <summary>Graphic Device</summary>
		ID3D11Device* GetDevice();
		/// <summary>2D描画Context</summary>
		ID3D11DeviceContext* GetDeviceContext();

		/// <summary>Projection Matrix</summary>
		/// <param name="projection">D3DXMATRIX 行列</param>
		void GetProjectionMatrix(D3DXMATRIX& projection);
		/// <summary>World Matrix</summary>
		/// <param name="world">D3DXMATRIX 行列</param>
		void GetWorldMatrix(D3DXMATRIX& world);
		/// <summary>Orthographic Matrix</summary>
		/// <param name="matrix">D3DXMATRIX 行列</param>
		void GetOrthoMatrix(D3DXMATRIX& matrix);

		/// <summary>VGAの情報</summary>
		/// <param name="info">VGAの情報</param>
		/// <param name="memory">VGAのメモリ</param>
		void GetVideoCardInfo(char* info, int& memory);

	private:
		bool m_vsync_enabled;								//VerticalSync
		int m_videoCardMemory;								//VideoCardのメモリ
		char m_videoCardDescription[128];					//VideoCardの情報
		IDXGISwapChain* m_swapChain;						//SwapChain
		ID3D11Device* m_device;								//Graphic Device
		ID3D11DeviceContext* m_deviceContext;				//2D描画Context
		ID3D11RenderTargetView* m_renderTargetView;			//Renderer Target
		ID3D11Texture2D* m_depthStencilBuffer;				//Depth Buffer
		ID3D11DepthStencilState* m_depthStencilState;		//Depth Stencil
		ID3D11DepthStencilView* m_depthStencilView;			//Depth Stencil
		ID3D11RasterizerState* m_rasterState;				//ラスタライズ

		D3DXMATRIX m_projectionMatrix;						//ProjectionMatrix
		D3DXMATRIX m_worldMatrix;							//WorldMatrix
		D3DXMATRIX m_orthoMatrix;							//OrthographicMatrix
	};
}