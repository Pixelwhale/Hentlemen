//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�L�������s������O�̒i�K
//		   �ړ��͈͂̏����A���̒i�K��AI�ɔC���邩�̔��f
//		  �i������ԂȂǁj
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_start.h>

using namespace BattleSystem;

PhaseStart::PhaseStart()
{
}

PhaseStart::PhaseStart(const PhaseStart&)
{
}

PhaseStart::~PhaseStart()
{
}


void PhaseStart::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kAIControl;
}

void PhaseStart::Update()
{
	//Todo:CharacterManager�ɃA�N�Z�X���āA���̃L������Player���̃L�����A�������łȂ����
	//next phase��Player�ɂ���

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_A))
	{
		m_next_phase = PhaseEnum::kAIControl;
		m_end_flag = true;
	}

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_P))
	{
		m_next_phase = PhaseEnum::kPlayerControl;
		m_end_flag = true;
	}
}

void PhaseStart::Draw()
{
	m_game_device->GetRenderer()->DrawString("�^�[���J�n\nA:AI�ɔC����\nP:Player����", Math::Vector2());
}


PhaseEnum PhaseStart::NextPhase()
{
	return m_next_phase;
}

bool PhaseStart::IsEnd()
{
	return m_end_flag;
}