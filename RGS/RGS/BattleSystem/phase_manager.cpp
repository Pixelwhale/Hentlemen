#include <BattleSystem\phase_manager.h>
#include <BattleSystem\Phase\phase_ai.h>
#include <BattleSystem\Phase\phase_animation.h>
#include <BattleSystem\Phase\phase_caculate.h>
#include <BattleSystem\Phase\phase_check_end.h>
#include <BattleSystem\Phase\phase_end.h>
#include <BattleSystem\Phase\phase_event.h>
#include <BattleSystem\Phase\phase_lose.h>
#include <BattleSystem\Phase\phase_player.h>
#include <BattleSystem\Phase\phase_start.h>
#include <BattleSystem\Phase\phase_wait.h>
#include <BattleSystem\Phase\phase_win.h>

using namespace BattleSystem;

PhaseManager::PhaseManager() 
{
}

PhaseManager::PhaseManager(const PhaseManager& phase_manager) 
{
}

PhaseManager::~PhaseManager()
{
}

void PhaseManager::Initialize(std::shared_ptr<Device::GameDevice> game_device)
{
	Clear();

	m_phases[PhaseEnum::kWait] = std::make_shared<PhaseWait>(game_device);
	m_phases[PhaseEnum::kStartTurn] = std::make_shared<PhaseStart>(game_device);
	m_phases[PhaseEnum::kPlayerControl] = std::make_shared<PhasePlayer>(game_device);
	m_phases[PhaseEnum::kAIControl] = std::make_shared<PhaseAI>(game_device);
	m_phases[PhaseEnum::kCaculate] = std::make_shared<PhaseCalculate>(game_device);
	m_phases[PhaseEnum::kAnimation] = std::make_shared<PhaseAnimation>(game_device);
	m_phases[PhaseEnum::kCheckEnd] = std::make_shared<PhaseCheckEnd>(game_device);
	m_phases[PhaseEnum::kEndTurn] = std::make_shared<PhaseEnd>(game_device);
	m_phases[PhaseEnum::kEvent] = std::make_shared<PhaseEvent>(game_device);
	m_phases[PhaseEnum::kWin] = std::make_shared<PhaseWin>(game_device);
	m_phases[PhaseEnum::kLose] = std::make_shared<PhaseLose>(game_device);

	ChangePhase(PhaseEnum::kWait);
}

void PhaseManager::Clear()
{
	for (auto& phase : m_phases)			//SharePointer�̒��ڂ�����
	{
		phase.second = 0;
	}
	
	m_phases.clear();						//�R���e�C�i�[�̒��g������
}

void PhaseManager::Update()
{
	if (m_current_phase.expired())			//�A�����ĂȂ�������ȉ������s���Ȃ�
		return;

	m_current_phase.lock()->Update();		//�X�V����

	if (m_current_phase.lock()->IsEnd())	//���̒i�K���I������玟�̒i�K�ֈڍs
	{
		ChangePhase(
			m_current_phase.lock()->NextPhase());
	}
}

void PhaseManager::Draw()
{
	if (!m_current_phase.expired())			//�A�����Ă��邩���m�F
		m_current_phase.lock()->Draw();		//���g��`��
}

void PhaseManager::ChangePhase(PhaseEnum phase_enum)
{
	m_phase_state = phase_enum;
	m_current_phase = m_phases[phase_enum];	//�w��̒i�K�ɕς��

	m_current_phase.lock()->Initialize();	//Phase���Ƃ̏���������
}

bool  PhaseManager::IsEnd() 
{
	return m_phase_state == PhaseEnum::kWin || m_phase_state == PhaseEnum::kLose;
}

bool  PhaseManager::IsWin() 
{
	return m_phase_state == PhaseEnum::kWin;
}