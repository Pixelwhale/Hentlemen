//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：敗北
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_lose.h>

using namespace BattleSystem;

PhaseLose::PhaseLose()
{
}

PhaseLose::PhaseLose(const PhaseLose&)
{
}

PhaseLose::~PhaseLose()
{
}


void PhaseLose::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kLose;
}

void PhaseLose::Update()
{
}

void PhaseLose::Draw()
{
}


PhaseEnum PhaseLose::NextPhase()
{
	return m_next_phase;
}

bool PhaseLose::IsEnd()
{
	return m_end_flag;
}