//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�s���I��
//		  (�^�[���̒ǉ��A�o�t�A�f�o�t�̃^�[�������Ȃ�)
//-------------------------------------------------------
#include <BattleSystem\Phase\phase_end.h>

using namespace BattleSystem;

PhaseEnd::PhaseEnd(std::shared_ptr<Device::GameDevice> game_device)
	:IPhase(game_device)
{
}

PhaseEnd::PhaseEnd(const PhaseEnd&)
	:IPhase(NULL)
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
	m_game_device->GetRenderer()->DrawString("�^�[���I��\nN:Next", Math::Vector2());
}


PhaseEnum PhaseEnd::NextPhase()
{
	return m_next_phase;
}

bool PhaseEnd::IsEnd()
{
	return m_end_flag;
}