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
	m_GraphicDevice->StartRender(1.0f, 1.0f, 1.0f, 1.0f);		//描画クリアColor


	m_GraphicDevice->EndRender();								//Swap
}

//終わっているか
bool Game::IsEnd()
{
	return m_endFlag;
}