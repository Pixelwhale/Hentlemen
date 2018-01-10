//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.14
// 内容　：キャラクターの移動について処理
//-------------------------------------------------------
#include "character_move.h"

using namespace Actor;

CharacterMove::CharacterMove(int move)
{
	m_base_move = move;
}

CharacterMove::~CharacterMove()
{
}

int CharacterMove::Move()
{
	return m_base_move;
}