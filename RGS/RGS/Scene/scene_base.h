//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.18
// ���e�@�F�V�[���̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Scene\scene_type.h>

namespace Scene
{
	class SceneBase
	{
	public:
		SceneBase();
		virtual void Initialize(SceneType previous) { m_end_flag = false; m_previous = previous; };
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;
		bool IsEnd() { return m_end_flag; };
		SceneType Next() { return m_next; };
	protected:
		std::shared_ptr<Device::Renderer> m_renderer;
		std::shared_ptr<Core::InputState> m_input;
		bool m_end_flag;
		SceneType m_next;
		SceneType m_previous;
	};
}