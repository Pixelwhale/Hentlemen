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

	m_gameDevice = std::make_shared<Device::GameDevice>(
		m_inputState,
		m_renderer,
		m_contentManager);
}

//���[�h�R���e���c
void Game::Load()
{
	m_contentManager->LoadTexture("load", ".png");
	m_contentManager->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_contentManager->LoadFont("MS UI Gothic", 50, 3);			//Word��Font��������
}

//�R���e���c���
void Game::Unload()
{
}

//�X�V����
void Game::Update()
{
	if (m_inputState->IsKeyTrigger(DIK_ESCAPE))
		m_endFlag = true;

	motionIndex++;
	if (motionIndex > 6)
		motionIndex = 0;
}

//�`�揈��
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	m_renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_renderer->DrawMotion("test", motionIndex, Math::Vector2(0, 100));

	m_renderer->DrawString("Hello World ����", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));

	m_renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_endFlag;
}