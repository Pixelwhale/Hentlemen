//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�FPlayer�̑��쏈��
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_player.h>

using namespace BattleSystem;

PhasePlayer::PhasePlayer(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhasePlayer::PhasePlayer(const PhasePlayer&)
	:IPhase(NULL)
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
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_A)) 
	{
		m_next_phase = PhaseEnum::kCaculate;
		m_end_flag = true;
	}

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_E))
	{
		m_next_phase = PhaseEnum::kEndTurn;
		m_end_flag = true;
	}
}

void PhasePlayer::Draw()
{
	m_game_device->GetRenderer()->DrawString("Player����\nA:Attack\nE:End Turn", Math::Vector2());
}


PhaseEnum PhasePlayer::NextPhase()
{
	return m_next_phase;
}

bool PhasePlayer::IsEnd()
{
	return m_end_flag;
}