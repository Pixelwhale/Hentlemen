//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�킢�̃V�[���B�I�v�V�����B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Battle : public SceneBase
	{
	public:
		Battle();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}