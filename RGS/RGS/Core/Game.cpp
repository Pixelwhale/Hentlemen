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
}

//ロードコンテンツ
void Game::Load()
{
	m_ContentManager->LoadTexture("load", ".png");
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
}

//描画処理
void Game::Draw()
{
	m_Renderer->Clear(0, 0, 0);

	m_Renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159 / 180,
		Color(1.0f, 0.1f, 0.1f, 0.3f));


	m_Renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_endFlag;
}