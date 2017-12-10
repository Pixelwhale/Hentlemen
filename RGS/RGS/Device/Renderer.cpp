//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
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
	DxLib::SetDrawScreen(DX_SCREEN_BACK);		//�`����BackBuffer�ɐݒ�
}

void Renderer::Release() 
{
	m_contents->Release();						//Texture���������
	m_contents = 0;
}

void Renderer::DrawTexture(std::string textureName, Math::Vector2 position) 
{
	DrawGraph(position.x, position.y, m_contents->TextureHandle(textureName), true);
}

void Renderer::DrawTexture(
	std::string textureName, Math::Vector2 position,
	Math::Vector2 pivot, Math::Vector2 scale,
	float angle, Color color, bool horizenFlip)
{
	color = color * color.A();						//Alpha�K�p
	SetDrawBright(color.r, color.g, color.b);		//�F�ݒ�

	DrawRotaGraph3(position.x, position.y, pivot.x, pivot.y,
		scale.x, scale.y, angle, m_contents->TextureHandle(textureName), true, horizenFlip);

	SetDrawBright(255, 255, 255);					//�F��߂�
}


void Renderer::Clear(int r, int g, int b)
{
	DxLib::SetBackgroundColor(r, g, b);			//ClearColor�ݒ�
	DxLib::ClearDrawScreen();					//��ʃN���A
}

void Renderer::Swap()
{
	DxLib::ScreenFlip();						//BackBuffer�ƌ���
}