//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FRender�@�\�𐮗������N���X
//-------------------------------------------------------
#include <Device\renderer.h>

using namespace Device;

Renderer::Renderer(std::shared_ptr<ContentManager> contents)
{
	m_contents = contents;
	m_depth_sort = std::make_shared<DepthSort>();
	m_depth_sort->Clear();
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

	m_depth_sort->Clear();
	m_depth_sort = 0;
}

void Renderer::Clear(int r, int g, int b)
{
	DxLib::SetBackgroundColor(r, g, b);			//ClearColor�ݒ�
	DxLib::ClearDrawScreen();					//��ʃN���A
	m_depth_sort->Clear();
}

void Renderer::Swap()
{
	DxLib::ScreenFlip();						//BackBuffer�ƌ���
}

std::shared_ptr<DepthSort> Renderer::GetDepthSort()
{
	return m_depth_sort;
}

#pragma region 2D Render�֘A

void Renderer::DrawTexture(std::string texture_name, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�
	DrawGraph((int)position.x, (int)position.y, m_contents->TextureHandle(texture_name), true);
	SetDrawBright(255, 255, 255);													//�F��߂�
}

void Renderer::DrawTexture(
	std::string texture_name, Math::Vector2 position,
	Math::Vector2 pivot, Math::Vector2 scale,
	float angle, Color color, bool horizen_flip)
{
	color = color * color.A();						//Alpha�K�p
	SetDrawBright(color.r, color.g, color.b);		//�F�ݒ�

	DrawRotaGraph3((int)position.x, (int)position.y, (int)pivot.x, (int)pivot.y,
		scale.x, scale.y, angle, m_contents->TextureHandle(texture_name), true, horizen_flip);

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawMotion(std::string texture_name, int index, Math::Vector2 position, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�
	DrawGraph((int)position.x, (int)position.y, m_contents->MotionHandle(texture_name, index), true);
	SetDrawBright(255, 255, 255);													//�F��߂�
}

#pragma endregion

#pragma region 3D Render�֘A

void Renderer::DrawModel(std::string model_name, Math::Vector3 position,
	Math::Vector3 size, Math::Vector3 rotation)
{
	int model = m_contents->ModelHandle(model_name);						//�n���h�����擾
	MV1SetScale(model, VGet(size.x, size.y, size.z));						//Scale
	MV1SetRotationXYZ(model, VGet(rotation.x, rotation.y, rotation.z));		//��]
	MV1SetPosition(model, VGet(position.x, position.y, position.z));		//�ړ�
	MV1DrawModel(model);													//�`��
}

void Renderer::DrawTexture3D(std::string texture_name, Math::Vector3 position,
	float scale, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),	//�ʒu
		0.5f, 0.5f,									//Pivot�|�C���g
		scale, 0.0,									//�傫���A��]
		m_contents->TextureHandle(texture_name),		//Tetxure Handle
		true, false);								//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawTexture3D(
	std::string texture_name, Math::Vector3 position,
	float scale, float angle, Color color, bool horizen_flip)
{
	color = color * color.A();						//Alpha�K�p
	SetDrawBright(color.r, color.g, color.b);		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),	//�ʒu
		0.5f, 0.5f,									//Pivot�|�C���g
		scale, angle,								//�傫���A��]
		m_contents->TextureHandle(texture_name),		//Tetxure Handle
		true, horizen_flip);							//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);					//�F��߂�
}

void Renderer::DrawMotion3D(std::string texture_name, int index,
	Math::Vector3 position, float scale, float alpha)
{
	SetDrawBright((int)(255 * alpha), (int)(255 * alpha), (int)(255 * alpha));		//�F�ݒ�

	DrawBillboard3D(
		VGet(position.x, position.y, position.z),		//�ʒu
		0.5f, 0.5f,										//Pivot�|�C���g
		scale, 0.0f,									//�傫���A��]
		m_contents->MotionHandle(texture_name, index),	//Tetxure Handle
		true, false);									//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);						//�F��߂�
}

void Renderer::DrawMotion3D(std::string texture_name, int index,
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
		m_contents->MotionHandle(texture_name, index),	//Tetxure Handle
		true, false);									//alpha�g�p, �������]

	SetDrawBright(255, 255, 255);						//�F��߂�
}

void Renderer::DrawTransparentObj()
{
	std::vector<TransparentObj> draw_list = m_depth_sort->DrawList();

	for (auto& obj : draw_list)
	{
		if (obj.index == -1)
		{
			DrawTexture3D(
				obj.texture_name,
				obj.position,
				obj.scale,
				obj.angle,
				obj.color);
			continue;
		}

		DrawMotion3D(
			obj.texture_name,
			obj.index,
			obj.position,
			obj.scale,
			obj.angle,
			obj.color);
	}
}

#pragma endregion

#pragma region �����֘A

void Renderer::DrawString(
	std::string text, std::string font_name, Math::Vector2 position, Color color,
	bool center)
{
	color = color * color.A();						//Alpha�K�p
	int handle = m_contents->FontHandle(font_name);
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
	int handle = m_contents->FontHandle("MS UI Gothic");
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
	int handle = m_contents->FontHandle("MS UI Gothic");
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


