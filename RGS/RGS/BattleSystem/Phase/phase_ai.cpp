//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�FAI�̍s������
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_ai.h>

using namespace BattleSystem;

PhaseAI::PhaseAI()
{
}

PhaseAI::PhaseAI(const PhaseAI&)
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
}

void PhaseAI::Draw()
{
}


PhaseEnum PhaseAI::NextPhase()
{
	return m_next_phase;
}

bool PhaseAI::IsEnd()
{
	return m_end_flag;
}