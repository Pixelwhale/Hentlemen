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
}

void PhaseStart::Draw()
{
}


PhaseEnum PhaseStart::NextPhase()
{
	return PhaseEnum::kStartTurn;
}

bool PhaseStart::IsEnd()
{
	return m_end_flag;
}