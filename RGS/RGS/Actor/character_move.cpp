//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.14
// 内容　：キャラクターの移動について処理
//-------------------------------------------------------
#include "character_move.h"

using namespace Actor;

CharacterMove::CharacterMove(int move, int jump)
{
	m_move = move;
	m_jump = jump;
}

CharacterMove::~CharacterMove()
{
}
