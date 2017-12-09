//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer();
		Renderer(const Renderer&);
		~Renderer();

		///<summary>����������</summary>
		void Initialize();
		///<summary>�V���b�g�_�E������</summary>
		void Release();

		///<summary>��ʃN���A</summary>
		///<param name="r">Red(0�`255)</param>
		///<param name="g">Green(0�`255)</param>
		///<param name="b">Blue(0�`255)</param>
		void Clear(int r, int g, int b);
		///<summary>BackBuffer�ƌ���</summary>
		void Swap();



	private:

	};
}