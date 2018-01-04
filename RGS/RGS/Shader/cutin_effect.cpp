//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.20 ～ 2017.12.21
// 内容　：必殺技のCut in処理
//-------------------------------------------------------
#include <Shader\cutin_effect.h>

using namespace Shader;

CutinEffect::CutinEffect()
{
	m_content = Device::GameDevice::GetInstance()->GetContent();	//コンテンツを取得
	m_shader_handle = m_content->PixelShaderHandle("cut_in");		//Shaderハンドルを取得

	m_source_handle = 0;		//ソース画像のハンドルを初期化
	m_mask_handle = 0;			//マスク画像のハンドルを初期化
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
	SetPosition(position);			//描画位置設定
	SourceTexture(source_name);		//ソースハンドルを取得
	MaskTexture(mask_name);			//マスクハンドルを取得

	int width;		//横サイズを取得する用変数
	int height;		//縦サイズを取得する用変数

	GetGraphTextureSize(m_source_handle, &width, &height);		//画像サイズを取得

	for (int i = 0; i < 4; i++)
	{
		m_vertice[i].pos = VGet(
			m_position.x + (i % 2) * width,						//Todo：サイズを変える
			m_position.y + (i / 2) * height, 0);
		m_vertice[i].rhw = 1.0f;
		m_vertice[i].dif = GetColorU8(255, 255, 255, 255);
		m_vertice[i].spc = GetColorU8(0, 0, 0, 0);
		m_vertice[i].u = m_vertice[i].su = (float)(i % 2);		//U座標
		m_vertice[i].v = m_vertice[i].sv = (float)(i / 2);		//V座標
	}
}

void CutinEffect::Draw(float rate, float alpha) 
{
	SetUsePixelShader(m_shader_handle);				//Shader使用
	SetUseTextureToShader(0, m_source_handle);		//ソース指定
	SetUseTextureToShader(1, m_mask_handle);		//Mask指定
	SetPSConstSF(0, rate);							//Rate指定
	SetPSConstSF(1, alpha);							//Alpha指定
	DrawPrimitive2DToShader(m_vertice, 4, DX_PRIMTYPE_TRIANGLESTRIP);	//描画
}