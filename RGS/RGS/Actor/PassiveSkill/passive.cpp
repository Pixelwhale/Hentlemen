//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.09
// 内容　：Passive Skill
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