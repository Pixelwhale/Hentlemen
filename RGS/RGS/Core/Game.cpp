//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
//-------------------------------------------------------
#include <Core\Game.h>

using namespace Core;

//����������
void Game::Initialize()
{
	m_endFlag = false;
	motionIndex = 0;
}

//���[�h�R���e���c
void Game::Load()
{
	m_ContentManager->LoadTexture("load", ".png");
	m_ContentManager->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_ContentManager->LoadFont("MS UI Gothic", 50, 3);			//Word��Font��������
}

//�R���e���c���
void Game::Unload()
{
}

//�X�V����
void Game::Update()
{
	if (m_InputState->IsKeyTrigger(DIK_ESCAPE))
		m_endFlag = true;

	motionIndex++;
	if (motionIndex > 6)
		motionIndex = 0;
}

//�`�揈��
void Game::Draw()
{
	m_Renderer->Clear(50, 50, 100);

	m_Renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	m_Renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_Renderer->DrawMotion("test", motionIndex, Math::Vector2(0, 100));

	m_Renderer->DrawString("Hello World ����", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));

	m_Renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_endFlag;
}