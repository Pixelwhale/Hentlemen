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
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_N)) 
	{
		m_end_flag = true;
	}
}

void PhaseWait::Draw()
{
	m_game_device->GetRenderer()->DrawString("Time Line��҂�\nN:Next", Math::Vector2());
}


PhaseEnum PhaseWait::NextPhase()
{
	return PhaseEnum::kStartTurn;
}

bool PhaseWait::IsEnd()
{
	return m_end_flag;
}