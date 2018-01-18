//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#include "character_base.h"

using namespace Actor;

CharacterBase::CharacterBase(int id, States states)
{
	m_id = id;
	m_battle = states;
}

CharacterBase::CharacterBase(int id)
{
	m_id = id;
}

CharacterBase::~CharacterBase()
{
	m_buff.~CharacterBuff();
}

void CharacterBase::Initialize()
{
	m_battle.FullRecovery();
}

void CharacterBase::Update()
{
}

bool CharacterBase::IsDead()
{
	return (m_battle.hp_current <= 0);
}