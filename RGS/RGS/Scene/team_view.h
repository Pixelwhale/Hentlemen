//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�`�[���̐��ځB�L�����̃f�[�^�A�A�C�e���A�X�L���A�����B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class TeamView : public SceneBase
	{
	public:
		TeamView();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}
