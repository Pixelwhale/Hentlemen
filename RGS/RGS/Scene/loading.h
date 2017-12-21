//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F�e�N�X�`���A���Ȃǂ����[�h����V�[��
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Scene\scene_base.h>

namespace Scene
{
	class Loading : SceneBase
	{
	public:
		Loading();
		void LoadContents();
		void UnloadContents();
		void Update();
		void Draw();
		void Shutdown();
	private:
		std::shared_ptr<Device::ContentManager> m_content;
	};
}