//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.20 �` 2017.12.21
// ���e�@�F�K�E�Z��Cut in����
//-------------------------------------------------------
#pragma once
#include <string>
#include <Device\game_device.h>
#include <Math\vector2.h>
#include <DX\DXLib\DxLib.h>

namespace Shader 
{
	class CutinEffect 
	{
	public:
		CutinEffect();
		CutinEffect(const CutinEffect&);
		~CutinEffect();

		///<summary>����������</summary>
		///<param name="position">�`��ʒu</param>
		///<param name="source_name">�`��\�[�X</param>
		///<param name="mask_name">�}�X�N�e�N�X�`���[</param>
		void Initialize(Math::Vector2 position,
			std::string source_name,
			std::string mask_name);

		///<summary>�`��</summary>
		///<param name="rate">Mask�ƂȂ�</param>
		void Draw(float rate, float alpha);

	private:
		///<summary>�ʒu�ݒ�</summary>
		///<param name="position">�`��ʒu</param>
		void SetPosition(Math::Vector2 position);
		///<summary>�\�[�X�ݒ�</summary>
		///<param name="position">�`��\�[�X</param>
		void SourceTexture(std::string source_name);
		///<summary>�}�X�N�ݒ�</summary>
		///<param name="position">�}�X�N�e�N�X�`���[</param>
		void MaskTexture(std::string source_name);

	private:
		std::shared_ptr<Device::ContentManager> m_content;		//Content

		VERTEX2DSHADER m_vertice[4];							//���_���
		Math::Vector2 m_position;								//�ʒu

		int m_shader_handle;	//Shader Handle
		int m_source_handle;	//�`��\�[�X��Handle
		int m_mask_handle;		//Mask�e�N�X�`���[��Handle
	};
}