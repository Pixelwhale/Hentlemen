//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：キャラが行動する前の段階
//		   移動範囲の処理、次の段階はAIに任せるかの判断
//		  （混乱状態など）
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
	//Todo:CharacterManagerにアクセスして、次のキャラがPlayer側のキャラ、且つ混乱でない状態
	//next phaseをPlayerにする

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
	m_game_device->GetRenderer()->DrawString("ターン開始\nA:AIに任せる\nP:Player操作", Math::Vector2());
}


PhaseEnum PhaseStart::NextPhase()
{
	return m_next_phase;
}

bool PhaseStart::IsEnd()
{
	return m_end_flag;
}