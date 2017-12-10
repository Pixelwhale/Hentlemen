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
}

//���[�h�R���e���c
void Game::Load()
{
	m_ContentManager->LoadTexture("load", ".png");
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
}

//�`�揈��
void Game::Draw()
{
	m_Renderer->Clear(0, 0, 0);

	m_Renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159 / 180,
		Color(1.0f, 0.1f, 0.1f, 0.3f));


	m_Renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_endFlag;
}