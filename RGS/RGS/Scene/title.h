//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�^�C�g���̃V�[���B�X�^�[�g�A���[�h�A�I�v�V�����B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Title : public SceneBase
	{
	public:
		Title();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}