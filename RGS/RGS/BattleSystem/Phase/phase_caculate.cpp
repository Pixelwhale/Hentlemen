//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�_���[�W�A�o�t�A�f�o�t�̌v�Z����
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_caculate.h>

using namespace BattleSystem;

PhaseCalculate::PhaseCalculate()
{
}

PhaseCalculate::PhaseCalculate(const PhaseCalculate&)
{
}

PhaseCalculate::~PhaseCalculate()
{
}


void PhaseCalculate::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kAnimation;
}

void PhaseCalculate::Update()
{

}

void PhaseCalculate::Draw()
{
}


PhaseEnum PhaseCalculate::NextPhase()
{
	return m_next_phase;
}

bool PhaseCalculate::IsEnd()
{
	return m_end_flag;
}