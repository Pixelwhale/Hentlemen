//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\content_manager.h>
#include <Device\depth_sort.h>
#include <Math\vector2.h>
#include <Color\color.h>
#include <memory>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer(std::shared_ptr<ContentManager> contents);
		Renderer(const Renderer&);
		~Renderer();

#pragma region Main System�֘A

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

		std::shared_ptr<DepthSort> GetDepthSort();

#pragma endregion


#pragma region 2D Render�֘A

		///<summary>Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="index">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="alpha">�����x</param>
		void DrawMotion(std::string texture_name, int index, Math::Vector2 position, float alpha = 1.0f);

		///<summary>Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="position">�`��ʒu</param>
		void DrawTexture(std::string texture_name, Math::Vector2 position, float alpha = 1.0f);

		///<summary>Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="position">�`��ʒu</param>
		///<param name="pivot">��]�A�X�P�[�����S</param>
		///<param name="scale">�g��k��</param>
		///<param name="angle">��]�i���W�A���j</param>
		///<param name="color">�F</param>
		///<param name="horizen_flip">�������]�H</param>
		void DrawTexture(
			std::string texture_name, Math::Vector2 position,
			Math::Vector2 pivot, Math::Vector2 scale,
			float angle, Color color, bool horizen_flip = false);
#pragma endregion


#pragma region 3D Render�֘A

		///<summary>���f����`��</summary>
		///<param name="model_name">Asset��</param>
		///<param name="position">�`��ʒu</param>
		///<param name="size">�傫��</param>
		///<param name="rotation">��]</param>
		void DrawModel(std::string model_name, Math::Vector3 position, 
			Math::Vector3 size, Math::Vector3 rotation);

		///<summary>3D��Ԃ�Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="index">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="alpha">�����x</param>
		void DrawMotion3D(std::string texture_name, int index, 
			Math::Vector3 position, float scales, float alpha = 1.0f);

		///<summary>3D��Ԃ�Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="index">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="scale">�傫���iWidth�̑傫���œ��{���j</param>
		///<param name="angle">��]�p�x�i���W�A���j</param>
		///<param name="color">�F</param>
		void DrawMotion3D(std::string texture_name, int index,
			Math::Vector3 position, float scale, float angle, Color color);

		///<summary>3D��Ԃ�Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="position">�`��ʒu</param>
		///<param name="scale">�g��k��(X��size����ŉ�pixel)</param>
		///<param name="alpha">�����x</param>
		void DrawTexture3D(std::string texture_name, Math::Vector3 position,
			float scale, float alpha = 1.0f);

		///<summary>3D��Ԃ�Texture��`��</summary>
		///<param name="texture_name">Asset��</param>
		///<param name="position">�`��ʒu</param>
		///<param name="scale">�g��k��(X��size����ŉ�pixel)</param>
		///<param name="angle">��]�i���W�A���j</param>
		///<param name="color">�F</param>
		///<param name="horizen_flip">�������]�H</param>
		void DrawTexture3D(
			std::string texture_name, Math::Vector3 position, 
			float scale, float angle, Color color, bool horizen_flip = false);

		void DrawTransparentObj();

#pragma endregion


#pragma region �����֘A

		///<summary>������`��</summary>
		///<param name="textureName">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="color">�F</param>
		///<param name="font_name">Font��</param>
		///<param name="center">�����u��</param>
		void DrawString(
			std::string text, std::string font_name, Math::Vector2 position, 
			Color color, bool center = false);

		///<summary>������`��</summary>
		///<param name="textureName">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="color">�F</param>
		///<param name="center">�����u��</param>
		void DrawString(
			std::string text, Math::Vector2 position, Color color,
			bool center = false);

		///<summary>������`��</summary>
		///<param name="textureName">������</param>
		///<param name="position">�`��ʒu</param>
		///<param name="center">�����u��</param>
		void DrawString(
			std::string text, Math::Vector2 position, bool center = false);

#pragma endregion

	private:
		std::shared_ptr<ContentManager> m_contents;				//Content Manager
		std::shared_ptr<DepthSort>		m_depth_sort;			//�`�揇���\�[�g����N���X
	};
}