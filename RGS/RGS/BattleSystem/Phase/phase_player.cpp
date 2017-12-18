//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：Playerの操作処理
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_player.h>

using namespace BattleSystem;

PhasePlayer::PhasePlayer()
{
}

PhasePlayer::PhasePlayer(const PhasePlayer&)
{
}

PhasePlayer::~PhasePlayer()
{
}


void PhasePlayer::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kEndTurn;
}

void PhasePlayer::Update()
{
	//Todo:攻撃がある場合はCalculate段階へ
}

void PhasePlayer::Draw()
{
}


PhaseEnum PhasePlayer::NextPhase()
{
	return m_next_phase;
}

bool PhasePlayer::IsEnd()
{
	return m_end_flag;
}