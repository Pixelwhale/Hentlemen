//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンを管理するマネージャー
//-------------------------------------------------------
#include <Scene\scene_manager.h>
#include <Scene\loading.h>

using namespace Scene;
using namespace std;

SceneManager::SceneManager()
{
	shared_ptr<Loading> pt = make_shared<Loading>();
	m_map[kLoading] = pt;
	m_current_scene = m_map[kLoading];
	m_current_type = kLoading;
}

void SceneManager::Add(SceneType type, std::shared_ptr<SceneBase> scene)
{
	m_map[type] = scene;
}

void SceneManager::Change(SceneType type)
{
	SceneType previous_type = m_current_type;
	m_current_type = type;
	m_current_scene = m_map[type];

	//if scene is not "pause" => initialize
	if (previous_type != kTeamView) m_current_scene.lock()->Initialize(previous_type);
}

void SceneManager::Update()
{
	m_current_scene.lock()->Update();
	if (m_current_scene.lock()->IsEnd())
	{
		m_current_scene.lock()->Shutdown();
		Change(m_current_scene.lock()->Next());
	}
}

void SceneManager::Draw()
{
	m_current_scene.lock()->Draw();
}