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
	SetDrawScreen(DX_SCREEN_BACK);		//�`����BackBuffer�ɐݒ�
	SetUseZBuffer3D(TRUE);				// �y�o�b�t�@��L���ɂ���
	SetWriteZBuffer3D(TRUE);			// �y�o�b�t�@�ւ̏������݂�L���ɂ���
}

void Renderer::Release() 
{
	m_contents->Release();						//Texture���������
	m_contents = 0;
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

#pragma region 2D Render�֘A

void Renderer::DrawTexture(std::string textureName, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�
	DrawGraph((int)position.x, (int)position.y, m_contents->TextureHandle(textureName), true);
	SetDrawBright(255, 255, 255);													//�F��߂�
}

void Renderer::DrawTexture(
	std::string textureName, Math::Vector2 position,
	Math::Vector2 pivot, Math::Vector2 scale,
	float angle, Color color, bool horizenFlip)
{
	color = color * color.A();						//Alpha�K�p
	SetDrawBright(color.r, color.g, color.b);		//�F�ݒ�

	DrawRotaGraph3((int)position.x, (int)position.y, (int)pivot.x, (int)pivot.y,
		scale.x, scale.y, angle, m_contents->TextureHandle(textureName), true, horizenFlip);

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawMotion(std::string textureName, int index, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�
	DrawGraph((int)position.x, (int)position.y, m_contents->MotionHandle(textureName, index), true);
	SetDrawBright(255, 255, 255);													//�F��߂�
}

#pragma endregion

#pragma region 3D Render�֘A

void Renderer::DrawTexture3D(std::string textureName, Math::Vector3 position, 
	float scale, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),	//�ʒu
		0.5f, 0.5f,									//Pivot�|�C���g
		scale, 0.0,									//�傫���A��]
		m_contents->TextureHandle(textureName),		//Tetxure Handle
		true, false);								//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawTexture3D(
	std::string textureName, Math::Vector3 position,
	float scale, float angle, Color color, bool horizenFlip)
{
	color = color * color.A();						//Alpha�K�p
	SetDrawBright(color.r, color.g, color.b);		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),	//�ʒu
		0.5f, 0.5f,									//Pivot�|�C���g
		scale, angle,								//�傫���A��]
		m_contents->TextureHandle(textureName),		//Tetxure Handle
		true, horizenFlip);							//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawMotion3D(std::string textureName, int index,
	Math::Vector3 position, float scale, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),		//�ʒu
		0.5f, 0.5f,										//Pivot�|�C���g
		scale, 0.0f,									//�傫���A��]
		m_contents->MotionHandle(textureName, index),	//Tetxure Handle
		true, false);									//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);						//�F��߂�
}

void Renderer::DrawMotion3D(std::string textureName, int index,
	Math::Vector3 position, float scale, float angle, Color color)
{
	SetDrawBright(
		(int)(color.r * color.A()), 
		(int)(color.g * color.A()), 
		(int)(color.b * color.A()));					//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),		//�ʒu
		0.5f, 0.5f,										//Pivot�|�C���g
		scale, angle,									//�傫���A��]
		m_contents->MotionHandle(textureName, index),	//Tetxure Handle
		true, false);									//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);						//�F��߂�
}

#pragma endregion

#pragma region �����֘A

void Renderer::DrawString(
	std::string text, std::string fontName, Math::Vector2 position, Color color,
	bool center)
{
	color = color * color.A();						//Alpha�K�p
	int handle = m_contents->FontHandle(fontName);
	if (center)
	{
		int xSize = GetDrawStringWidthToHandle(
			text.c_str(), text.length(), handle);
		position.x -= (int)(xSize / 2.0f);
	}

	DrawStringToHandle(
		(int)position.x, (int)position.y,						//�ʒu
		text.c_str(),								//����
		GetColor(color.r, color.g, color.b),		//�F
		handle);									//�g�pFont
}

void Renderer::DrawString(
	std::string text, Math::Vector2 position, Color color,
	bool center)
{
	color = color * color.A();						//Alpha�K�p
	int handle = m_contents->FontHandle("Arial");
	if (center)
	{
		int xSize = GetDrawStringWidthToHandle(
			text.c_str(), text.length(), handle);
		position.x -= (int)(xSize / 2.0f);
	}

	DrawStringToHandle(
		(int)position.x, (int)position.y,						//�ʒu
		text.c_str(),								//����
		GetColor(color.r, color.g, color.b),		//�F
		handle);									//�g�pFont
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
		(int)position.x, (int)position.y,		//�ʒu
		text.c_str(),				//����
		GetColor(0, 0, 0),			//�F
		handle);					//�g�pFont
}

#pragma endregion


