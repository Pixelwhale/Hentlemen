//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�i�s�i�K�̃}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <map>
#include <memory>
#include <BattleSystem\i_phase.h>
#include <BattleSystem\phase_enum.h>

namespace BattleSystem 
{
	class PhaseManager 
	{
	public:
		PhaseManager();
		PhaseManager(const PhaseManager& phase_manager);
		~PhaseManager();

		///<summary>����������</summary>
		void Initialize(std::shared_ptr<Device::GameDevice> game_device);
		///<summary>Phase�S������</summary>
		void Clear();

		///<summary>Phase���Ƃ̍X�V����</summary>
		void Update();
		///<summary>Phase���Ƃ̕`�揈��</summary>
		void Draw();

		///<summary>�I����Ă��邩</summary>
		bool IsEnd();
		///<summary>�����Ȃ̂�</summary>
		bool IsWin();

		///<summary>Phase��؂�ւ��</summary>
		///<param name="phase_enum">Phase�̏�Ԃ��w��</param>
		void ChangePhase(PhaseEnum phase_enum);

	private:
		std::map<PhaseEnum, std::shared_ptr<IPhase>> m_phases;		//Phase�̃R���e�C�i�[
		std::weak_ptr<IPhase> m_current_phase;						//����Phase�̃C���X�^���X
		PhaseEnum m_phase_state;									//���݂�Phase
	};
}