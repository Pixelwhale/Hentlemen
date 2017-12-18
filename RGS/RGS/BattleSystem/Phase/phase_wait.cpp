//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：タイムラインの処理と演出する段階
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_wait.h>

using namespace BattleSystem;

PhaseWait::PhaseWait()
{
}

PhaseWait::PhaseWait(const PhaseWait&)
{
}

PhaseWait::~PhaseWait()
{
}


void PhaseWait::Initialize()
{
	m_end_flag = false;
}

void PhaseWait::Update()
{
}

void PhaseWait::Draw()
{
}


PhaseEnum PhaseWait::NextPhase()
{
	return PhaseEnum::kStartTurn;
}

bool PhaseWait::IsEnd()
{
	return m_end_flag;
}