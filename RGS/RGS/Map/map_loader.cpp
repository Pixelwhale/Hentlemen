//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：MapChipをファイルから読み込む
//-------------------------------------------------------
#include <Map\map_loader.h>
#include <iostream>
#include <fstream>

using namespace Map;
using namespace std;

MapLoader::MapLoader()
{
}

MapLoader::MapLoader(const MapLoader&)
{
}

MapLoader::~MapLoader()
{
}

void MapLoader::Clear() 
{
	m_map_chip.clear();		//ダミーデータを解放
	m_y_size = 0;			//Y軸の値をReset
}

void MapLoader::Load(string file_name)
{
	ifstream file_stream(file_name.c_str(), ios::in);		//ファイルストリーム
	string input_string;									//読み取るStringの変数
	vector<string> map_info;								//読み取った資料を保存する容器

	m_y_size = 0;											//サイズをリセット

	while (getline(file_stream, input_string, '"'))			//一行つず読み取る　"で切る（Split）
	{
		if (input_string.length() == 0 ||					//何も入ってなっかた場合
			input_string[0] == ',')							//最初が,の場合
			continue;										//スキップ

		if (input_string == "\n")							//改行記号
		{
			++m_y_size;										//行数を更新（Y軸に追加）
			continue;										//保存しない
		}

		map_info.push_back(input_string);					//文字データを保存
	}

	file_stream.close();									//ファイルを閉じる

	for (auto& grid_info:map_info)							//読み取った文字データを一周する
	{
		vector<int> blocks;									//一マスの情報
		for (auto& height_info:grid_info)
		{
			if (height_info == ' ' ||						//空欄、区切りは無視
				height_info == ',')
				continue;
			if (height_info == 'N')							//NullのNに来たら次のマスへ
				break;

			blocks.push_back(height_info - '0');			//マス情報を追加（数字として）
		}

		Grid grid(blocks);									//一マスの情報を生成
		m_map_chip.push_back(grid);							//マップ情報に追加
	}
}

std::vector<Grid> MapLoader::GetMapChip()
{
	return m_map_chip;
}

int MapLoader::GetXSize() 
{
	return m_map_chip.size() / m_y_size;					//全部の数　/　Y軸の数　＝　X軸の数
}