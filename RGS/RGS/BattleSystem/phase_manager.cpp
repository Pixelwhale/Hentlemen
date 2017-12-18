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
	m_battle_state = BattleState::kBattle;	//戦闘状態にする

	//ToDo:Phaseの実装と追加
}

void PhaseManager::Clear()
{
	for (auto& phase : m_phases)			//SharePointerの注目を解除
	{
		phase.second = 0;
	}
	
	m_phases.clear();						//コンテイナーの中身を消す
}

void PhaseManager::Update()
{
	if (m_current_phase.expired())			//連結してなっかたら以下を実行しない
		return;

	m_current_phase.lock()->Update();		//更新処理

	if (m_current_phase.lock()->IsEnd())	//この段階が終わったら次の段階へ移行
	{
		ChangePhase(
			m_current_phase.lock()->NextPhase());
	}
}

void PhaseManager::Draw()
{
	if (!m_current_phase.expired())			//連結しているかを確認
		m_current_phase.lock()->Draw();		//中身を描画
}

BattleState PhaseManager::CurrentState()
{
	return m_battle_state;
}

void PhaseManager::ChangePhase(PhaseEnum phase_enum)
{
	m_current_phase = m_phases[phase_enum];	//指定の段階に変わる
}