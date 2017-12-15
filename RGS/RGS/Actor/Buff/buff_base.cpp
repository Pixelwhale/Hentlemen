//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.15
// 内容　：バフとデバフの処理
//-------------------------------------------------------
#include <Actor\Buff\buff_base.h>

using namespace Actor;

BuffBase::BuffBase(float duration)
{
	m_duration = duration;
}

BuffBase::~BuffBase()
{
}

void BuffBase::Update()
{
}