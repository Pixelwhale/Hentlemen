//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�FAI�̍s������
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_ai.h>

using namespace BattleSystem;

PhaseAI::PhaseAI(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhaseAI::PhaseAI(const PhaseAI&)
	:IPhase(NULL)
{
}

PhaseAI::~PhaseAI()
{
}


void PhaseAI::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kEndTurn;
}

void PhaseAI::Update()
{
	//Todo:�U��������ꍇ��Calculate�i�K��
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_A)) 
	{
		m_next_phase = PhaseEnum::kCaculate;
		m_end_flag = true;
	}

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_E))
	{
		m_next_phase = PhaseEnum::kEndTurn;
		m_end_flag = true;
	}
}

void PhaseAI::Draw()
{
	m_game_device->GetRenderer()->DrawString("AI�̃^�[��\nA:Attack\nE:End Turn", Math::Vector2());
}


PhaseEnum PhaseAI::NextPhase()
{
	return m_next_phase;
}

bool PhaseAI::IsEnd()
{
	return m_end_flag;
}