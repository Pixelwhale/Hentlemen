//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：進行中の段階
//-------------------------------------------------------
#pragma once

namespace BattleSystem 
{
	enum PhaseEnum
	{
		kWait,				//順番を待つ
		kMoveRange,			//移動範囲を計算
		kPlayerControl,		//プレイヤー操作
		kAIControl,			//AI行動
		kCaculate,			//Buff,Damage計算
		kAnimation,			//アニメーション演出
		kCheckEnd,			//勝敗条件を確認
		kEvent,				//イベントの終了を待つ
	};
}