//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Render機能を整理したクラス
//-------------------------------------------------------
#include <Device\Renderer.h>

using namespace Device;

Renderer::Renderer(std::shared_ptr<ContentManager> contents)
{
	m_contents = contents;
}

Renderer::Renderer(const Renderer&)
{
}

Renderer::~Renderer()
{
}

void Renderer::Initialize()
{
	DxLib::SetDrawScreen(DX_SCREEN_BACK);		//描画先をBackBufferに設定
}

void Renderer::Release() 
{
	m_contents->Release();						//Textureを解放処理
	m_contents = 0;
}

void Renderer::DrawTexture(std::string textureName, Math::Vector2 position) 
{
	DrawGraph(position.x, position.y, m_contents->TextureHandle(textureName), true);
}


void Renderer::Clear(int r, int g, int b)
{
	DxLib::SetBackgroundColor(r, g, b);			//ClearColor設定
	DxLib::ClearDrawScreen();					//画面クリア
}

void Renderer::Swap()
{
	DxLib::ScreenFlip();						//BackBufferと交換
}