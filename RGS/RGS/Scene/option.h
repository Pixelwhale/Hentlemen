//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�I�v�V�����̃V�[���B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Option : public SceneBase
	{
	public:
		Option();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}