//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
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