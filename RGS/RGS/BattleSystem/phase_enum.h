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
		kStartTurn,			//開始時の処理、移動範囲の計算など
		kPlayerControl,		//プレイヤー操作
		kAIControl,			//AI行動
		kCaculate,			//Buff,Damage計算
		kAnimation,			//アニメーション演出
		kCheckEnd,			//勝敗条件を確認
		kEndTurn,			//操作終了時の処理（Buff、Debuffのターン処理、ターンの追加など）
		kEvent,				//イベントの終了を待つ
		kWin,				//勝利
		kLose,				//敗北
	};
}