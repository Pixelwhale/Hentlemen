//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.09
// ���e�@�FPassive Skill
//-------------------------------------------------------
#include "passive.h"

using namespace Actor;

Passive::Passive()
{
}

Passive::~Passive()
{
}

void Passive::Initialize()
{
	for (int i = 0;i < 16;++i)
	{
		m_passive[i] = 0;
	}
}