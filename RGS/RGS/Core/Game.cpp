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
}

//ロードコンテンツ
void Game::Load()
{
	m_ContentManager->LoadTexture("load", ".png");
	m_ContentManager->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_ContentManager->LoadFont("MS UI Gothic", 50, 3);			//WordでFont名を見る
}

//コンテンツ解放
void Game::Unload()
{
}

//更新処理
void Game::Update()
{
	if (m_InputState->IsKeyTrigger(DIK_ESCAPE))
		m_endFlag = true;

	motionIndex++;
	if (motionIndex > 6)
		motionIndex = 0;
}

//描画処理
void Game::Draw()
{
	m_Renderer->Clear(50, 50, 100);

	m_Renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	m_Renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_Renderer->DrawMotion("test", motionIndex, Math::Vector2(0, 100));

	m_Renderer->DrawString("Hello World 漢字", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));

	m_Renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_endFlag;
}