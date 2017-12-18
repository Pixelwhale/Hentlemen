//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：進行段階のマネージャー
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
		std::map<PhaseEnum, std::shared_ptr<IPhase>> m_phases;		//Phaseのコンテイナー
		std::weak_ptr<IPhase> m_current_phase;						//現在のPhase

		BattleState m_battle_state;									//戦闘状態（勝ち、負け）
	};
}