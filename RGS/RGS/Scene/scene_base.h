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
		SceneBase(Device::GameDevice& game_device) : m_game_device(game_device) {};
		virtual void Initialize(SceneType previous) { m_end_flag = false; m_previous = previous; };
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;
		bool EndFlag() { return m_end_flag; };
		SceneType Next() { return m_next; };
	private:
		Device::GameDevice& m_game_device;
		bool m_end_flag;
		SceneType m_next;
		SceneType m_previous;
	};
}