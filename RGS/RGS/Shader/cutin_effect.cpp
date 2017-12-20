#include <Shader\cutin_effect.h>

using namespace Shader;

CutinEffect::CutinEffect()
{
	m_content = Device::GameDevice::GetInstance()->GetContent();
	m_shader_handle = m_content->PixelShaderHandle("cut_in");

	m_source_handle = 0;
	m_mask_handle = 0;
}

CutinEffect::CutinEffect(const CutinEffect&)
{
}

CutinEffect::~CutinEffect()
{
}

void CutinEffect::SetPosition(Math::Vector2 position)
{
	m_position = position;
}

void CutinEffect::SourceTexture(std::string source_name)
{
	m_source_handle = m_content->TextureHandle(source_name);
}

void CutinEffect::MaskTexture(std::string source_name)
{
	m_mask_handle = m_content->TextureHandle(source_name);
}


void CutinEffect::Initialize(
	Math::Vector2 position,
	std::string source_name,
	std::string mask_name)
{
	SetPosition(position);
	SourceTexture(source_name);
	MaskTexture(mask_name);

	int width;
	int height;

	GetGraphTextureSize(m_source_handle, &width, &height);

	for (int i = 0; i < 4; i++)
	{
		m_vertice[i].pos = VGet(
			m_position.x + (i % 2) * width, 
			m_position.y + (i / 2) * height, 0);
		m_vertice[i].rhw = 1.0f;
		m_vertice[i].dif = GetColorU8(255, 255, 255, 255);
		m_vertice[i].spc = GetColorU8(0, 0, 0, 0);
		m_vertice[i].u = m_vertice[i].su = (float)(i % 2);
		m_vertice[i].v = m_vertice[i].sv = (float)(i / 2);
	}
}

void CutinEffect::Draw() 
{
	SetUsePixelShader(m_shader_handle);
	SetUseTextureToShader(0, m_source_handle);
	SetUseTextureToShader(1, m_mask_handle);
	DrawPrimitive2DToShader(m_vertice, 4, DX_PRIMTYPE_TRIANGLESTRIP);
}