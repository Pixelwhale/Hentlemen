//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンを管理するマネージャー
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
		SceneType m_current_type;
		std::weak_ptr<SceneBase> m_current_scene;
	};
}