//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.14
// ���e�@�F�o�g���ŃL�����N�^�[���Ǘ�����}�l�[�W���[
//-------------------------------------------------------
#include "character_manager.h"

using namespace Actor;

CharacterManager::CharacterManager()
{
}

void CharacterManager::Initialize()
{
	for (auto chara : m_character_list)
	{
		chara.c->BattleInitialize();
	}
}

void CharacterManager::Update()
{
	for (auto chara : m_character_list)
	{
		chara.c->Update();
	}
}

void CharacterManager::AddCharacter(std::shared_ptr<CharacterBase> character, int time)
{
	m_character_list.push_back(BattleChara(character, time));
}