//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：一マスのブロックを保存する構造体
//-------------------------------------------------------
#pragma once
#include <vector>

namespace Map
{
	struct Grid
	{
		///<summary>一マスのブロックを保存する構造体</summary>
		///<param name="height">ブロックをまとめた配列</param>
		Grid(std::vector<int> height)
		{
			blocks = height;
		}

		///<summary>積み上げた分の数</summary>
		int Height() { return blocks.size(); }

		std::vector<int> blocks;					//一マスのブロック
	};
}