//-------------------------------------------------------
// ì¬ÒF—Ñ‰À‰b
// ì¬“úF2017.12.18
// “à—e@F”s–k
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
	m_game_device->GetRenderer()->DrawString("”s–k", Math::Vector2());
}

PhaseEnum PhaseLose::NextPhase()
{
	return m_next_phase;
}

bool PhaseLose::IsEnd()
{
	return m_end_flag;
}