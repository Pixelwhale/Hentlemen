//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Render機能を整理したクラス
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>

namespace Device 
{
	class Renderer 
	{
	public:
		Renderer();
		Renderer(const Renderer&);
		~Renderer();

		///<summary>初期化処理</summary>
		void Initialize();
		///<summary>シャットダウン処理</summary>
		void Release();

		///<summary>画面クリア</summary>
		///<param name="r">Red(0～255)</param>
		///<param name="g">Green(0～255)</param>
		///<param name="b">Blue(0～255)</param>
		void Clear(int r, int g, int b);
		///<summary>BackBufferと交換</summary>
		void Swap();



	private:

	};
}