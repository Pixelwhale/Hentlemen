//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.15
//-------------------------------------------------------
#include "player.h"

using namespace Actor;

Player::Player(int id)
{
};

States Player::BattleStates()
{
	//basis + passive states
	return m_basis;
};