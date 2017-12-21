//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F�e�N�X�`���A���Ȃǂ����[�h����V�[��
//-------------------------------------------------------
#include <Scene\loading.h>

using namespace Scene;

Loading::Loading()
{
	m_content = Device::GameDevice::GetInstance()->GetContent();
}

void Loading::LoadContents()
{
	m_content->LoadTexture("load", ".png");
	m_content->LoadTexture("test", ".png");
	m_content->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_content->LoadFont("MS UI Gothic", 50, 3);

	m_content->LoadModel("test", ".mv1");
}

void Loading::UnloadContents()
{
}

void Loading::Update()
{
}

void Loading::Draw()
{
	m_renderer->DrawString("Loading", Math::Vector2(0, 0));
}

void Loading::Shutdown()
{
}
