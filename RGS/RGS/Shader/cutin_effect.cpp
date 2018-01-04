//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.20 �` 2017.12.21
// ���e�@�F�K�E�Z��Cut in����
//-------------------------------------------------------
#include <Shader\cutin_effect.h>

using namespace Shader;

CutinEffect::CutinEffect()
{
	m_content = Device::GameDevice::GetInstance()->GetContent();	//�R���e���c���擾
	m_shader_handle = m_content->PixelShaderHandle("cut_in");		//Shader�n���h�����擾

	m_source_handle = 0;		//�\�[�X�摜�̃n���h����������
	m_mask_handle = 0;			//�}�X�N�摜�̃n���h����������
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
	SetPosition(position);			//�`��ʒu�ݒ�
	SourceTexture(source_name);		//�\�[�X�n���h�����擾
	MaskTexture(mask_name);			//�}�X�N�n���h�����擾

	int width;		//���T�C�Y���擾����p�ϐ�
	int height;		//�c�T�C�Y���擾����p�ϐ�

	GetGraphTextureSize(m_source_handle, &width, &height);		//�摜�T�C�Y���擾

	for (int i = 0; i < 4; i++)
	{
		m_vertice[i].pos = VGet(
			m_position.x + (i % 2) * width,						//Todo�F�T�C�Y��ς���
			m_position.y + (i / 2) * height, 0);
		m_vertice[i].rhw = 1.0f;
		m_vertice[i].dif = GetColorU8(255, 255, 255, 255);
		m_vertice[i].spc = GetColorU8(0, 0, 0, 0);
		m_vertice[i].u = m_vertice[i].su = (float)(i % 2);		//U���W
		m_vertice[i].v = m_vertice[i].sv = (float)(i / 2);		//V���W
	}
}

void CutinEffect::Draw(float rate, float alpha) 
{
	SetUsePixelShader(m_shader_handle);				//Shader�g�p
	SetUseTextureToShader(0, m_source_handle);		//�\�[�X�w��
	SetUseTextureToShader(1, m_mask_handle);		//Mask�w��
	SetPSConstSF(0, rate);							//Rate�w��
	SetPSConstSF(1, alpha);							//Alpha�w��
	DrawPrimitive2DToShader(m_vertice, 4, DX_PRIMTYPE_TRIANGLESTRIP);	//�`��
}