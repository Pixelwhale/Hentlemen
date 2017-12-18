//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�s���I��
//		  (�^�[���̒ǉ��A�o�t�A�f�o�t�̃^�[�������Ȃ�)
//-------------------------------------------------------
#pragma once
#include <BattleSystem\i_phase.h>

namespace BattleSystem
{
	class PhaseEnd : public IPhase
	{
	public:
		PhaseEnd();
		PhaseEnd(const PhaseEnd&);
		~PhaseEnd();

		///<summary>����������</summary>
		virtual void Initialize();
		///<summary>�X�V����</summary>
		virtual void Update();
		///<summary>�`�揈��</summary>
		virtual void Draw();

		///<summary>���̒i�K</summary>
		virtual PhaseEnum NextPhase();
		///<summary>���̒i�K�͏I����Ă��邩</summary>
		virtual bool IsEnd();

	private:
		bool m_end_flag;			//Phase�I���̃t���O
		PhaseEnum m_next_phase;		//���̒i�K
	};
}