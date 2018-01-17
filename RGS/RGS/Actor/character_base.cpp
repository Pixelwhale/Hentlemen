//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#include <Actor\character_base.h>

using namespace Actor;

CharacterBase::CharacterBase(int id)
{
	m_id = id;
}

CharacterBase::~CharacterBase()
{
	m_buff.~CharacterBuff();
}

void CharacterBase::BattleInitialize()
{

}

void CharacterBase::Update()
{
}

bool CharacterBase::IsDead()
{
	return (m_states.m_hp_current <= 0);
}