//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\ContentManager.h>
#include <Math\Vector2.h>
#include <Color\Color.h>
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

		///<summary>Texture��`��</summary>
		///<param name="textureName">Asset��</param>
		///<param name="position">�`��ʒu</param>
		void DrawTexture(std::string textureName, Math::Vector2 position);

		///<summary>Texture��`��</summary>
		///<param name="textureName">Asset��</param>
		///<param name="position">�`��ʒu</param>
		///<param name="pivot">��]�A�X�P�[�����S</param>
		///<param name="scale">�g��k��</param>
		///<param name="angle">��]�i���W�A���j</param>
		///<param name="color">�F</param>
		///<param name="horizenFlip">�������]�H</param>
		void DrawTexture(
			std::string textureName, Math::Vector2 position, 
			Math::Vector2 pivot, Math::Vector2 scale, 
			float angle, Color color, bool horizenFlip = false);

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