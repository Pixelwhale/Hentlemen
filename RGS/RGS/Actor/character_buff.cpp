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
	//m_instant_list.clear();
	m_buff_list.clear();
}

void CharacterBuff::Initialize()
{
}

void CharacterBuff::UpdateTime(BuffFunction &sbattle)
{
	for (auto buff : m_buff_list)
	{
		buff->Update(sbattle);
	}
}

void CharacterBuff::UpdateStates(States& sbuff, States& sdebuff)
{
}

void CharacterBuff::AddBuff(std::shared_ptr<BuffBase> buff)
{
	m_buff_list.push_back(buff);
}
