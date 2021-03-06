//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：行動終了
//		  (ターンの追加、バフ、デバフのターン処理など)
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_end.h>

using namespace BattleSystem;

PhaseEnd::PhaseEnd()
{
}

PhaseEnd::PhaseEnd(const PhaseEnd&)
{
}

PhaseEnd::~PhaseEnd()
{
}


void PhaseEnd::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kCheckEnd;
}

void PhaseEnd::Update()
{
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_N)) 
	{
		m_end_flag = true;
	}
}

void PhaseEnd::Draw()
{
	m_game_device->GetRenderer()->DrawString("ターン終了\nN:Next", Math::Vector2());
}


PhaseEnum PhaseEnd::NextPhase()
{
	return m_next_phase;
}

bool PhaseEnd::IsEnd()
{
	return m_end_flag;
}