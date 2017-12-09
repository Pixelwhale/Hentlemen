//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04�`2017.12.09
// ���e�@�F�����_���[
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

		/// <summary>������</summary>
		/// <param name="hwnd">Window Handle</param>
		bool Initialize(HWND hwnd);
		/// <summary>�V���b�g�_�E������</summary>
		void Shutdown();

		/// <summary>ClearColor�ݒ� �`��J�n</summary>
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