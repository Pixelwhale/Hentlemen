//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：Playerの操作処理
//-------------------------------------------------------
#pragma once
#include <BattleSystem\i_phase.h>

namespace BattleSystem
{
	class PhasePlayer : public IPhase
	{
	public:
		PhasePlayer(std::shared_ptr<Device::GameDevice> game_device);
		PhasePlayer(const PhasePlayer&);
		~PhasePlayer();

		///<summary>初期化処理</summary>
		virtual void Initialize();
		///<summary>更新処理</summary>
		virtual void Update();
		///<summary>描画処理</summary>
		virtual void Draw();

		///<summary>次の段階</summary>
		virtual PhaseEnum NextPhase();
		///<summary>この段階は終わっているか</summary>
		virtual bool IsEnd();

	private:
		bool m_end_flag;			//Phase終了のフラグ
		PhaseEnum m_next_phase;		//次の段階
	};
}