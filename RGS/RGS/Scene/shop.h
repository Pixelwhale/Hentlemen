//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�V���b�v�̃V�[���B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Shop : public SceneBase
	{
	public:
		Shop();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}