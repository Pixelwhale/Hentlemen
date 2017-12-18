//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：ダメージ、バフ、デバフの計算処理
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