//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F�e�N�X�`���A���Ȃǂ����[�h����V�[��
//-------------------------------------------------------
#include <Scene\loading.h>

using namespace Scene;

void Loading::LoadContents()
{
	m_game_device.GetContent()->LoadTexture("load", ".png");
	m_game_device.GetContent()->LoadTexture("test", ".png");
	m_game_device.GetContent()->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_game_device.GetContent()->LoadFont("MS UI Gothic", 50, 3);

	m_game_device.GetContent()->LoadModel("test", ".mv1");
}

void Loading::UnloadContents()
{
}

void Loading::Update()
{
}

void Loading::Draw()
{
	m_game_device.GetRenderer()->DrawString("Loading", Math::Vector2(0, 0));
}