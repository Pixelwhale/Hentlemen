//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�C�x���g��҂���
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
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_N)) 
	{
		m_end_flag = true;
	}
}

void PhaseEvent::Draw()
{
	m_game_device->GetRenderer()->DrawString("�C�x���g\nN:Next", Math::Vector2());
}


PhaseEnum PhaseEvent::NextPhase()
{
	return m_next_phase;
}

bool PhaseEvent::IsEnd()
{
	return m_end_flag;
}