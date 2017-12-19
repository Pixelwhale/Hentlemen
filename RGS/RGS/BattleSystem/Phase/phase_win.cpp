//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：戦闘勝利
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_win.h>

using namespace BattleSystem;

PhaseWin::PhaseWin(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhaseWin::PhaseWin(const PhaseWin&)
	:IPhase(NULL)
{
}

PhaseWin::~PhaseWin()
{
}


void PhaseWin::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kWin;
}

void PhaseWin::Update()
{
}

void PhaseWin::Draw()
{
	m_game_device->GetRenderer()->DrawString("勝利", Math::Vector2());
}


PhaseEnum PhaseWin::NextPhase()
{
	return m_next_phase;
}

bool PhaseWin::IsEnd()
{
	return m_end_flag;
}