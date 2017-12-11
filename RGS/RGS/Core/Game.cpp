//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：Gameの基本処理
//-------------------------------------------------------
#include <Core\Game.h>

using namespace Core;

//初期化処理
void Game::Initialize()
{
	m_endFlag = false;
	motionIndex = 0;

	m_gameDevice = std::make_shared<Device::GameDevice>(
		m_inputState,
		m_renderer,
		m_contentManager);

	m_gameDevice->GetProjector()->SetPosition(Math::Vector3(10, 20, 10));
	m_gameDevice->GetProjector()->SetTarget(Math::Vector3(0, 0, 0));
}

//ロードコンテンツ
void Game::Load()
{
	m_contentManager->LoadTexture("load", ".png");
	m_contentManager->LoadTexture("test", ".png");
	m_contentManager->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_contentManager->LoadFont("MS UI Gothic", 50, 3);			//WordでFont名を見る
}

//コンテンツ解放
void Game::Unload()
{
}

//更新処理
void Game::Update()
{
	if (m_inputState->IsKeyTrigger(DIK_ESCAPE))
		m_endFlag = true;

	motionIndex++;
	if (motionIndex > 6)
		motionIndex = 0;
}

//描画処理
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	m_renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_renderer->DrawMotion("test", motionIndex, Math::Vector2(0, 100));

	m_renderer->DrawString("Hello World 漢字", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));
	m_renderer->DrawString("こんにちは。世界", "MS UI Gothic", Math::Vector2(600, 300), Color(120, 120, 50));

	for (int i = 0; i < 16; i++) 
	{
		DrawSphere3D(VGet(i % 4 * 10, 0.0f, i / 4 * 10), 5.0f, 36, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
	}


	m_renderer->DrawTexture3D("test", Math::Vector3(-5, 0, -3), 50, 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
	m_renderer->DrawTexture3D("test", Math::Vector3(0, 0, 0), 50, 0, Color(1.0f, 1.0f, 1.0f, 1.0f));

	m_renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_endFlag;
}