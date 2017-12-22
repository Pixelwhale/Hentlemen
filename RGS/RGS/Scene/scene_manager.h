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

		///<summary>�V�[���̎��̂𐶐�����</summary>
		void Initialize();

		void Update();
		void Draw();
	private:
		std::map<SceneType, std::shared_ptr<SceneBase>> m_map;
		SceneType m_current_type;
		std::weak_ptr<SceneBase> m_current_scene;
		
		void Add(SceneType type, std::shared_ptr<SceneBase> scene);
		void Change(SceneType type);
	};
}