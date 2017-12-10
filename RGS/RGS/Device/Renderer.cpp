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

void Renderer::Clear(int r, int g, int b)
{
	DxLib::SetBackgroundColor(r, g, b);			//ClearColor設定
	DxLib::ClearDrawScreen();					//画面クリア
}

void Renderer::Swap()
{
	DxLib::ScreenFlip();						//BackBufferと交換
}

#pragma region 2D Render関連

void Renderer::DrawTexture(std::string textureName, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//色設定
	DrawGraph((int)position.x, (int)position.y, m_contents->TextureHandle(textureName), true);
	SetDrawBright(255, 255, 255);													//色を戻す
}

void Renderer::DrawMotion(std::string textureName, int index, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//色設定
	DrawGraph((int)position.x, (int)position.y, m_contents->MotionHandle(textureName, index), true);
	SetDrawBright(255, 255, 255);													//色を戻す
}

void Renderer::DrawTexture(
	std::string textureName, Math::Vector2 position,
	Math::Vector2 pivot, Math::Vector2 scale,
	float angle, Color color, bool horizenFlip)
{
	color = color * color.A();						//Alpha適用
	SetDrawBright(color.r, color.g, color.b);		//色設定

	DrawRotaGraph3((int)position.x, (int)position.y, (int)pivot.x, (int)pivot.y,
		scale.x, scale.y, angle, m_contents->TextureHandle(textureName), true, horizenFlip);

	SetDrawBright(255, 255, 255);					//色を戻す
}


#pragma endregion


#pragma region 文字関連

void Renderer::DrawString(
	std::string text, std::string fontName, Math::Vector2 position, Color color,
	bool center)
{
	color = color * color.A();						//Alpha適用
	int handle = m_contents->FontHandle(fontName);
	if (center)
	{
		int xSize = GetDrawStringWidthToHandle(
			text.c_str(), text.length(), handle);
		position.x -= (int)(xSize / 2.0f);
	}

	DrawStringToHandle(
		(int)position.x, (int)position.y,						//位置
		text.c_str(),								//文字
		GetColor(color.r, color.g, color.b),		//色
		handle);									//使用Font
}

void Renderer::DrawString(
	std::string text, Math::Vector2 position, Color color,
	bool center)
{
	color = color * color.A();						//Alpha適用
	int handle = m_contents->FontHandle("Arial");
	if (center)
	{
		int xSize = GetDrawStringWidthToHandle(
			text.c_str(), text.length(), handle);
		position.x -= (int)(xSize / 2.0f);
	}

	DrawStringToHandle(
		(int)position.x, (int)position.y,						//位置
		text.c_str(),								//文字
		GetColor(color.r, color.g, color.b),		//色
		handle);									//使用Font
}

void Renderer::DrawString(
	std::string text, Math::Vector2 position, bool center)
{
	int handle = m_contents->FontHandle("Arial");
	if (center) 
	{
		int xSize = GetDrawStringWidthToHandle(
			text.c_str(), text.length(), handle);
		position.x -= (int)(xSize / 2.0f);
	}

	DrawStringToHandle(
		(int)position.x, (int)position.y,		//位置
		text.c_str(),				//文字
		GetColor(0, 0, 0),			//色
		handle);					//使用Font
}

#pragma endregion


