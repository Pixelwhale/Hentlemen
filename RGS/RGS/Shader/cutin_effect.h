//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.20 ～ 2017.12.21
// 内容　：必殺技のCut in処理
//-------------------------------------------------------
#pragma once
#include <string>
#include <Device\game_device.h>
#include <Math\vector2.h>
#include <DX\DXLib\DxLib.h>

namespace Shader 
{
	class CutinEffect 
	{
	public:
		CutinEffect();
		CutinEffect(const CutinEffect&);
		~CutinEffect();

		///<summary>初期化処理</summary>
		///<param name="position">描画位置</param>
		///<param name="source_name">描画ソース</param>
		///<param name="mask_name">マスクテクスチャー</param>
		void Initialize(Math::Vector2 position,
			std::string source_name,
			std::string mask_name);

		///<summary>描画</summary>
		///<param name="rate">Maskとなる基準</param>
		void Draw(float rate, float alpha);

	private:
		///<summary>位置設定</summary>
		///<param name="position">描画位置</param>
		void SetPosition(Math::Vector2 position);
		///<summary>ソース設定</summary>
		///<param name="position">描画ソース</param>
		void SourceTexture(std::string source_name);
		///<summary>マスク設定</summary>
		///<param name="position">マスクテクスチャー</param>
		void MaskTexture(std::string source_name);

	private:
		std::shared_ptr<Device::ContentManager> m_content;		//Content

		VERTEX2DSHADER m_vertice[4];							//頂点情報
		Math::Vector2 m_position;								//位置

		int m_shader_handle;	//Shader Handle
		int m_source_handle;	//描画ソースのHandle
		int m_mask_handle;		//MaskテクスチャーのHandle
	};
}