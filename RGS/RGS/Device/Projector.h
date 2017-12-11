//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.11
// ���e�@�FProjector
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Math\Vector3.h>

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

		///<summary>�J�����ʒu��ݒ�</summary>
		///<param name="position">�ʒu</param>
		void SetPosition(Math::Vector3 position);
		///<summary>���ړ_��ݒ�</summary>
		///<param name="target">���ږڕW</param>
		void SetTarget(Math::Vector3 target);

	private:
		///<summary>View���X�V�i�ړ��Ȃǂ�����ꍇ�j</summary>
		void UpdateView();

	private:
		VECTOR m_position;		//Projector�̈ʒu
		VECTOR m_target;		//���ړ_
	};
}