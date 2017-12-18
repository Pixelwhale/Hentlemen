//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：イベントを待つ処理
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_event.h>

using namespace BattleSystem;

PhaseEvent::PhaseEvent()
{
}

PhaseEvent::PhaseEvent(const PhaseEvent&)
{
}

PhaseEvent::~PhaseEvent()
{
}


void PhaseEvent::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kWait;
}

void PhaseEvent::Update()
{
}

void PhaseEvent::Draw()
{
}


PhaseEnum PhaseEvent::NextPhase()
{
	return m_next_phase;
}

bool PhaseEvent::IsEnd()
{
	return m_end_flag;
}