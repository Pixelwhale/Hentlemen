//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Render機能を整理したクラス
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\ContentManager.h>
#include <Math\Vector2.h>
#include <memory>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer(std::shared_ptr<ContentManager> contents);
		Renderer(const Renderer&);
		~Renderer();

		///<summary>初期化処理</summary>
		void Initialize();
		///<summary>シャットダウン処理</summary>
		void Release();

		void DrawTexture(std::string textureName, Math::Vector2 position);

		///<summary>画面クリア</summary>
		///<param name="r">Red(0～255)</param>
		///<param name="g">Green(0～255)</param>
		///<param name="b">Blue(0～255)</param>
		void Clear(int r, int g, int b);
		///<summary>BackBufferと交換</summary>
		void Swap();

	private:
		std::shared_ptr<ContentManager> m_contents;				//Content Manager

	};
}