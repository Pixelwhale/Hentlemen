//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�_���[�W�A�o�t�A�f�o�t�̌v�Z����
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_caculate.h>

using namespace BattleSystem;

PhaseCalculate::PhaseCalculate(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhaseCalculate::PhaseCalculate(const PhaseCalculate&)
	:IPhase(NULL)
{
}

PhaseCalculate::~PhaseCalculate()
{
}


void PhaseCalculate::Initialize()
{
	m_end_flag = false;
	m_next_phase = PhaseEnum::kAnimation;
}

void PhaseCalculate::Update()
{
	if (m_game_device->GetInput()->IsKeyTrigger(DIK_N)) 
	{
		m_end_flag = true;
	}
}

void PhaseCalculate::Draw()
{
	m_game_device->GetRenderer()->DrawString("�_���[�W�v�Z�A�o�t�v�Z\nN:Next", Math::Vector2());
}


PhaseEnum PhaseCalculate::NextPhase()
{
	return m_next_phase;
}

bool PhaseCalculate::IsEnd()
{
	return m_end_flag;
}