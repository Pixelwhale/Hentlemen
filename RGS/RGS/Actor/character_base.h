//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Actor\character_states.h>
#include <Actor\character_move.h>

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(CharacterStates states, CharacterMove move) : m_states(states), m_move(move) {};
		~CharacterBase();
	protected:
		CharacterStates& m_states;
		CharacterMove& m_move;
	};
}