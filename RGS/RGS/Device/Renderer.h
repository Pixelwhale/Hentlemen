//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\ContentManager.h>
#include <Math\Vector2.h>
#include <memory>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer(std::shared_ptr<ContentManager> contents);
		Renderer(const Renderer&);
		~Renderer();

		///<summary>����������</summary>
		void Initialize();
		///<summary>�V���b�g�_�E������</summary>
		void Release();

		void DrawTexture(std::string textureName, Math::Vector2 position);

		///<summary>��ʃN���A</summary>
		///<param name="r">Red(0�`255)</param>
		///<param name="g">Green(0�`255)</param>
		///<param name="b">Blue(0�`255)</param>
		void Clear(int r, int g, int b);
		///<summary>BackBuffer�ƌ���</summary>
		void Swap();

	private:
		std::shared_ptr<ContentManager> m_contents;				//Content Manager

	};
}