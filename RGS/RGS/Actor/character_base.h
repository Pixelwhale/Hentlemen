//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include "states.h"
#include "character_move.h"
#include "character_buff.h"
#include "Buff\buff_base.h"

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(int id);
		~CharacterBase();

		//(enemy) read file and set battle states
		//(both)add passives to character_buff
		virtual void BattleInitialize();

		void Update();

		bool IsDead();

	protected:
		int m_id;
		States m_states;		//battle states
		CharacterMove m_move;
		CharacterBuff m_buff;
	};
}