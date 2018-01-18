//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.10
// 内容：キャラとバフにかかわる処理
//-------------------------------------------------------
#include "character_buff.h"

using namespace Actor;

CharacterBuff::CharacterBuff()
{
}

CharacterBuff::~CharacterBuff()
{
	m_instant_list.clear();
	m_buff_list.clear();
}

void CharacterBuff::Initialize()
{
	m_instant_list.clear();
	m_buff_list.clear();
}

#pragma region instant buff
void CharacterBuff::UpdateInstant()
{
	for (auto buff : m_instant_list)
	{
		buff->Update();
	}
}
void CharacterBuff::AddInstant(std::shared_ptr<BuffBase> buff)
{
	if (buff->IsInstant())
	{
		m_buff_list.push_back(buff);
	}
}
#pragma endregion

#pragma region buff
void CharacterBuff::UpdateBuff()
{
	for (auto buff : m_buff_list)
	{
		buff->Update();
	}
}
void CharacterBuff::AddBuff(std::shared_ptr<BuffBase> buff)
{
	if (!buff->IsInstant())
	{
		m_buff_list.push_back(buff);
	}
}
#pragma endregion

#pragma region passive
void CharacterBuff::UpdatePassive()
{
	for (auto buff : m_passive_list)
	{
		buff->Update();
	}
}
void CharacterBuff::AddPassive(std::shared_ptr<BuffBase> buff)
{
	if (!buff->IsInstant())
	{
		m_passive_list.push_back(buff);
	}
}
#pragma endregion
