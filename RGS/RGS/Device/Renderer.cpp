//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Render機能を整理したクラス
//-------------------------------------------------------
#include <Device\Renderer.h>

using namespace Device;

Renderer::Renderer()
{
}

Renderer::Renderer(const Renderer&)
{
}

Renderer::~Renderer()
{
}

void Renderer::Initialize()
{
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
}

void Renderer::Release() 
{

}

void Renderer::Clear(int r, int g, int b)
{
	DxLib::SetBackgroundColor(r, g, b);
	DxLib::ClearDrawScreen();
}

void Renderer::Swap()
{
	DxLib::ScreenFlip();
}