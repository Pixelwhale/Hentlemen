//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：アニメーションの演出
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_animation.h>

using namespace BattleSystem;

PhaseAnimation::PhaseAnimation(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhaseAnimation::PhaseAnimation(const PhaseAnimation&)
	:IPhase(NULL)
{
}

PhaseAnimation::~PhaseAnimation()
{
}


void PhaseAnimation::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kCheckEnd;
}

void PhaseAnimation::Update()
{
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_N)) 
	{
		m_end_flag = true;
	}
}

void PhaseAnimation::Draw()
{
	m_game_device->GetRenderer()->DrawString("アニメーション演出\nN:Next", Math::Vector2());
}


PhaseEnum PhaseAnimation::NextPhase()
{
	return m_next_phase;
}

bool PhaseAnimation::IsEnd()
{
	return m_end_flag;
}