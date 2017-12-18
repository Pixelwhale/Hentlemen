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
}

void PhaseCheckEnd::Draw()
{
}


PhaseEnum PhaseCheckEnd::NextPhase()
{
	return m_next_phase;
}

bool PhaseCheckEnd::IsEnd()
{
	return m_end_flag;
}