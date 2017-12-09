//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04～2017.12.09
// 内容　：レンダラー
//-------------------------------------------------------
#pragma once
#include <Windows.h>
#include <Core\DXGraphic.h>
#include <memory>

namespace Core
{
	class GraphicDevice
	{
	public:
		GraphicDevice();
		GraphicDevice(const GraphicDevice&);
		~GraphicDevice();

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
		void StartRender(float r, float g, float b, float a);
		/// <summary>Swap Buffer</summary>
		void EndRender();

	private:
		std::shared_ptr<DXGraphic> m_DXDevice;					//DX Library
	};
}