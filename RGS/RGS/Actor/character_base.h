//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Actor\character_states.h>
#include <Actor\character_move.h>
#include <Actor\character_buff.h>
#include <Actor\Buff\buff_base.h>

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(CharacterStates states, CharacterMove move, CharacterBuff buff) : m_states(states), m_move(move), m_buff(buff) {};
		~CharacterBase();
		void Initialize();
		void Update();
	protected:
		CharacterStates & m_states;
		CharacterMove& m_move;
		CharacterBuff& m_buff;
	};
}