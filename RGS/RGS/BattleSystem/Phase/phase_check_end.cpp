//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：戦闘終了条件の確認
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_check_end.h>

using namespace BattleSystem;

PhaseCheckEnd::PhaseCheckEnd()
{
}

PhaseCheckEnd::PhaseCheckEnd(const PhaseCheckEnd&)
{
}

PhaseCheckEnd::~PhaseCheckEnd()
{
}


void PhaseCheckEnd::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kWait;
}

void PhaseCheckEnd::Update()
{
	//Todo:条件確認したあとに次のPhaseをWinかLoseにする
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_W)) 
	{
		m_next_phase = PhaseEnum::kWin;
		m_end_flag = true;
	}

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_L))
	{
		m_next_phase = PhaseEnum::kLose;
		m_end_flag = true;
	}

	if (m_game_device->GetInput()->IsKeyTrigger(DIK_C))
	{
		m_next_phase = PhaseEnum::kWait;
		m_end_flag = true;
	}
}

void PhaseCheckEnd::Draw()
{
	m_game_device->GetRenderer()->DrawString("終了条件確認\nW:Win\nL:Lose\nC:Continue", Math::Vector2());
}


PhaseEnum PhaseCheckEnd::NextPhase()
{
	return m_next_phase;
}

bool PhaseCheckEnd::IsEnd()
{
	return m_end_flag;
}