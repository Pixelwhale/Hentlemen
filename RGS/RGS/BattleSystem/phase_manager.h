//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：進行段階のマネージャー
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

		///<summary>初期化処理</summary>
		void Initialize(std::shared_ptr<Device::GameDevice> game_device);
		///<summary>Phase全部消す</summary>
		void Clear();

		///<summary>Phaseごとの更新処理</summary>
		void Update();
		///<summary>Phaseごとの描画処理</summary>
		void Draw();

		///<summary>終わっているか</summary>
		bool IsEnd();
		///<summary>勝利なのか</summary>
		bool IsWin();

		///<summary>Phaseを切り替わる</summary>
		///<param name="phase_enum">Phaseの状態を指定</param>
		void ChangePhase(PhaseEnum phase_enum);

	private:
		std::map<PhaseEnum, std::shared_ptr<IPhase>> m_phases;		//Phaseのコンテイナー
		std::weak_ptr<IPhase> m_current_phase;						//現在Phaseのインスタンス
		PhaseEnum m_phase_state;									//現在のPhase
	};
}