#include <BattleSystem\phase_manager.h>

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

void PhaseManager::Initialize()
{
	Clear();
	m_battle_state = BattleState::kBattle;	//�퓬��Ԃɂ���

	//ToDo:Phase�̎����ƒǉ�
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

BattleState PhaseManager::CurrentState()
{
	return m_battle_state;
}

void PhaseManager::ChangePhase(PhaseEnum phase_enum)
{
	m_current_phase = m_phases[phase_enum];	//�w��̒i�K�ɕς��
}