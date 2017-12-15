//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.11
// ���e�@�FProjector
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Math\vector3.h>

namespace Device 
{
	class Projector 
	{
	public:
		Projector();
		Projector(const Projector&);
		~Projector();
		///<summary>����������</summary>
		void Initialize();

		///<summary>�ڕW�Ƃ̑��Έʒu��ݒ�</summary>
		///<param name="relative_position">Projector�ƖڕW�̑��Έʒu�֌W</param>
		void SetRelativePosition(Math::Vector3 relative_position);
		///<summary>���ړ_��ݒ�</summary>
		///<param name="target">���ږڕW</param>
		void SetTarget(Math::Vector3 target);

		///<summary>��]</summary>
		///<param name="angle">��]�p�x�i���W�A���j</param>
		void Rotate(float angle);
		///<summary>�g��A�k��</summary>
		///<param name="rate">�傫����ZoomOut�A��������ZoomIn�i0�ȉ��͏㉺�t�]�j</param>
		void Zoom(float rate);

		///<summary>�J�����̈ʒu</summary>
		Math::Vector3 Position();

	private:
		///<summary>View���X�V�i�ړ��Ȃǂ�����ꍇ�j</summary>
		void UpdateView();

	private:
		VECTOR m_position;				//Projector�̈ʒu
		VECTOR m_target;				//���ړ_
		VECTOR m_relative_position;		//Projector�ƖڕW�̑��Έʒu
	};
}