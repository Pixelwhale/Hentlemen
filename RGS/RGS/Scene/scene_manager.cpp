#include <Scene\scene_manager.h>

using namespace Scene;

void SceneManager::Add(SceneType type, std::shared_ptr<SceneBase> scene)
{
	m_map[type] = scene;
}

void SceneManager::Change(SceneType type)
{
	m_current_scene = m_map[type];
	m_current_scene.lock->Initialize();
}

void SceneManager::Update()
{
	m_current_scene.lock->Update();
	if (m_current_scene.lock->EndFlag())
	{
		m_current_scene.lock->Shutdown();
		Change(m_current_scene.lock->Next());
	}
}

void SceneManager::Draw()
{
	m_current_scene.lock->Draw();
}