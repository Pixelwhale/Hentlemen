//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：MapChipをファイルから読み込む
//-------------------------------------------------------
#pragma once
#include <string>
#include <vector>
#include <Map\map_grid.h>

namespace Map 
{
	class MapLoader 
	{
	public:
		MapLoader();
		MapLoader(const MapLoader&);
		~MapLoader();

		///<summary>読み込んだダミーデータを削除</summary>
		void Clear();
		///<summary>ファイルからデータを読み込む</summary>
		void Load(std::string file_name);

		///<summary>マップチップを取得</summary>
		std::vector<Grid> GetMapChip();
		///<summary>マップチップのX軸の数</summary>
		int GetXSize();

	private:
		std::vector<Grid> m_map_chip;		//マップチップ
		int m_y_size;						//Y軸の数
	};
}