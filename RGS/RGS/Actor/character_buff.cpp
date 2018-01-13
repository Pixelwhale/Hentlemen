//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.10
// ���e�F�L�����ƃo�t�ɂ�����鏈��
//-------------------------------------------------------
#include <Actor\character_buff.h>

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
	for (std::shared_ptr<BuffBase> buff : m_instant_list)
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
void CharacterBuff::Update()
{
	for (std::shared_ptr<BuffBase> buff : m_buff_list)
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
