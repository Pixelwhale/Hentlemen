//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.14
// 内容　：バトルでキャラクターを管理するマネージャー
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