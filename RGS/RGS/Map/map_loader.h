//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：MapChipをファイルから読み込む
//-------------------------------------------------------
#pragma once
#include <string>
#include <vector>
#include <map>
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
		///<param name="map_file_name">マップのファイル名</param>
		///<param name="block_file_name">対応するブロックのファイル名</param>
		void Load(std::string map_file_name, std::string block_file_name);

		///<summary>マップチップを取得</summary>
		std::vector<Grid> GetMapChip();
		///<summary>マップチップのX軸の数</summary>
		int GetXSize();

		std::map<int, std::string> GetBlockDef();

	private:
		///<summary>ファイルからマップ情報を読み取る</summary>
		void ReadMapData(std::string file_name);
		///<summary>読み取ったデータをマップ情報に設定</summary>
		void SetupMapData();
		///<summary>ファイルからブロック情報を読み取る</summary>
		void ReadBlockData(std::string file_name);
		///<summary>読み取ったデータをブロック情報に設定</summary>
		void SetupBlockData();

	private:
		std::vector<std::string> m_data_info;		//読み取った資料を保存する容器

		std::vector<Grid> m_map_chip;				//マップチップ
		int m_y_size;								//Y軸の数

		std::map<int, std::string> m_block_info;	//Block定義
	};
}