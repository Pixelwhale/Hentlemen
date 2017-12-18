//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.18
// ���e�@�F�V�[�����Ǘ�����}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();
		void Add(SceneType type, std::shared_ptr<SceneBase> scene);
		void Change(SceneType type);
		void Update();
		void Draw();
	private:
		std::map<SceneType, std::shared_ptr<SceneBase>> m_map;
		std::weak_ptr<SceneBase> m_current_scene;
	};
}