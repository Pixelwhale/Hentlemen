//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�L�������s������O�̒i�K
//		   �ړ��͈͂̏����A���̒i�K��AI�ɔC���邩�̔��f
//		  �i������ԂȂǁj
//-------------------------------------------------------
#pragma once
#include <BattleSystem\i_phase.h>

namespace BattleSystem
{
	class PhaseStart : public IPhase
	{
	public:
		PhaseStart(std::shared_ptr<Device::GameDevice> game_device);
		PhaseStart(const PhaseStart&);
		~PhaseStart();

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