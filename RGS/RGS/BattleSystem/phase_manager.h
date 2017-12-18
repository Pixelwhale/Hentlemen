//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�i�s�i�K�̃}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <map>:
#include <memory>;
#include <BattleSystem\i_phase.h>
#include <BattleSystem\phase_enum.h>
#include <BattleSystem\battle_state.h>

namespace BattleSystem 
{
	class PhaseManager 
	{
	public:
		PhaseManager();
		PhaseManager(const PhaseManager& phase_manager);
		~PhaseManager();

		void Initialize();
		void Clear();

		void Update();
		void Draw();

		BattleState CurrentState();

		void ChangePhase(PhaseEnum phase_enum);

	private:
		std::map<PhaseEnum, std::shared_ptr<IPhase>> m_phases;		//Phase�̃R���e�C�i�[
		std::weak_ptr<IPhase> m_current_phase;						//���݂�Phase

		BattleState m_battle_state;									//�퓬��ԁi�����A�����j
	};
}