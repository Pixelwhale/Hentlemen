//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�FPlayer�̑��쏈��
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
	//Todo:�U��������ꍇ��Calculate�i�K��
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