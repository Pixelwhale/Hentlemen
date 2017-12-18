//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：AIの行動処理
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
	//Todo:攻撃がある場合はCalculate段階へ
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