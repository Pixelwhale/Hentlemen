//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
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