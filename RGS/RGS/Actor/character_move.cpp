//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.14
// ���e�@�F�L�����N�^�[�̈ړ��ɂ��ď���
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