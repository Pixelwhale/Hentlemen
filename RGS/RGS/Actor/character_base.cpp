//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Actor\character_base.h>

using namespace Actor;

CharacterBase::~CharacterBase()
{
}

void CharacterBase::Initialize()
{
	m_buff_list.clear();
}

void CharacterBase::Update()
{
	for (std::shared_ptr<BuffBase> buff : m_buff_list)
	{
		buff->Update();
	}
}

void CharacterBase::AddBuff(std::shared_ptr<BuffBase> buff)
{
	m_buff_list.push_back(buff);
}