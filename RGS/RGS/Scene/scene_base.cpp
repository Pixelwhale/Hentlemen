//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.18
// ���e�@�F�V�[���̃x�[�X�N���X
//-------------------------------------------------------
#include <Scene\scene_base.h>

using namespace Scene;
using namespace Device;

Scene::SceneBase()
{
	m_renderer = GameDevice::GetInstance()->GetRenderer();
	m_input = GameDevice::GetInstance()->GetInput();
}