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