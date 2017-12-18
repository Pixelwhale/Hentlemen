//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�퓬�I�������̊m�F
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_check_end.h>

using namespace BattleSystem;

PhaseCheckEnd::PhaseCheckEnd()
{
}

PhaseCheckEnd::PhaseCheckEnd(const PhaseCheckEnd&)
{
}

PhaseCheckEnd::~PhaseCheckEnd()
{
}


void PhaseCheckEnd::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kWait;
}

void PhaseCheckEnd::Update()
{
	//Todo:�����m�F�������ƂɎ���Phase��Win��Lose�ɂ���
}

void PhaseCheckEnd::Draw()
{
}


PhaseEnum PhaseCheckEnd::NextPhase()
{
	return m_next_phase;
}

bool PhaseCheckEnd::IsEnd()
{
	return m_end_flag;
}