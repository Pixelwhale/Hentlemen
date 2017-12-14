//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.12
// ���e�@�F�����̂���e�N�X�`���̓\�[�g���ĕ`�悷��K�v��
//			����̂ŁA���̂��߂̃N���X
//-------------------------------------------------------
#pragma once
#include <vector>
#include <Color\color.h>
#include <Math\vector3.h>
#include <DX\DXLib\DxLib.h>

namespace Device
{
	struct TransparentObj
	{
		///<summary>������������e�N�X�`����`�悷��Object</summary>
		///<param name="texture_name">�A�Z�b�g��</param>
		///<param name="index">Motion��Index�iMotion���Ȃ��ꍇ��-1�j</param>
		///<param name="position">�ʒu</param>
		///<param name="scale">�傫��(X���̃s�N�Z����)</param>
		///<param name="angle">��]�p�x�i���W�A���j</param>
		///<param name="color">�F</param>
		TransparentObj(std::string texture_name, int index,
			Math::Vector3 position,
			float scale, float angle, Color color)
			:texture_name(texture_name), index(index),
			position(position),
			scale(scale), angle(angle), color(color)
		{
			projection_dis = 0;
		}

		std::string		texture_name;		//�A�Z�b�g��
		int				index;				//Motion��Index�iMotion���Ȃ��ꍇ��-1�j
		Math::Vector3	position;			//�ʒu
		float			projection_dis;		//�J�����Ƃ̈ʒu
		float			scale;				//�傫��(X���̃s�N�Z����)
		float			angle;				//��]�i���W�A���j
		Color			color;				//�F
	};

	class DepthSort
	{
	public:
		DepthSort();
		DepthSort(const DepthSort&);
		~DepthSort();

		///<summary>������������ǉ�</summary>
		///<param name="obj">�����������̐ݒ�</param>
		void AddTransparentObj(TransparentObj obj);
		///<summary>List�ɂ�����̂��N���A</summary>
		void Clear();

		///<summary>�\�[�g�i��납��O�ɕ`�揇��z�u�j</summary>
		///<param name="projector_pos">�J�����̈ʒu</param>
		void Sort(Math::Vector3 projector_pos);
		///<summary>�`�惊�X�g</summary>
		std::vector<TransparentObj>& DrawList();

	private:
		std::vector<TransparentObj>	m_drawList;			//�`�惊�X�g

	};
}