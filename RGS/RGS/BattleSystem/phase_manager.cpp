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

void PhaseManager::ChangePhase(PhaseEnum phase_enum)
{
	m_phase_state = phase_enum;
	m_current_phase = m_phases[phase_enum];	//指定の段階に変わる

	m_current_phase.lock()->Initialize();	//Phaseごとの初期化処理
}

bool  PhaseManager::IsEnd() 
{
	return m_phase_state == PhaseEnum::kWin || m_phase_state == PhaseEnum::kLose;
}

bool  PhaseManager::IsWin() 
{
	return m_phase_state == PhaseEnum::kWin;
}