//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�^�C�����C���̏����Ɖ��o����i�K
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