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
	m_data_info.clear();	//ダミーデータを解放
	m_map_chip.clear();		//ダミーデータを解放
	m_block_info.clear();	//ダミーデータを解放
	m_y_size = 0;			//Y軸の値をReset
}

void MapLoader::Load(string map_file_name, string block_file_name)
{
	ReadMapData(map_file_name);

	SetupMapData();
	
	ReadBlockData(block_file_name);

	SetupBlockData();
}

void MapLoader::ReadMapData(string file_name)
{
	ifstream file_stream(file_name.c_str(), ios::in);		//ファイルストリーム
	string input_string;									//読み取るStringの変数

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

		m_data_info.push_back(input_string);				//文字データを保存
	}

	file_stream.close();									//ファイルを閉じる
}

void MapLoader::SetupMapData() 
{
	m_map_chip.clear();										//ダミーデータを解放

	for (auto& grid_info : m_data_info)						//読み取った文字データを一周する
	{
		vector<int> blocks;									//一マスの情報
		for (auto& height_info : grid_info)
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

	m_data_info.clear();									//ダミーデータを解放
}

void MapLoader::ReadBlockData(std::string file_name) 
{
	ifstream file_stream(file_name.c_str(), ios::in);		//ファイルストリーム
	string input_string;									//読み取るStringの変数

	while (getline(file_stream, input_string, '\n'))		//一行つず読み取る\nで切る（Split）
	{
		if (input_string.length() == 0)						//何も入ってなっかた場合
			continue;										//スキップ
		
		int erase_chara = 1;								//削除する文字数
		string type_data = "";								//BlockType
		string asset_data = "";								//Texture名

		for (auto& character : input_string) 
		{
			if (character == ',')							//,でSplit
			{
				input_string.erase(0, erase_chara);			//残ったデータ
				asset_data = input_string;
				break;
			}

			type_data += character;							//先頭データ追加
			++erase_chara;
		}

		m_data_info.push_back(type_data);					//Typeデータを保存
		m_data_info.push_back(asset_data);					//Textureデータを保存
	}

	file_stream.close();									//ファイルを閉じる
}

void MapLoader::SetupBlockData() 
{
	m_block_info.clear();										//ダミーデータを解放

	for (unsigned int i = 0; i < m_data_info.size(); ++i) 
	{
		int block_type = 0;
		sscanf_s(m_data_info[i].c_str(), "%d", &block_type);	//BlockTypeをintに変換

		++i;													//次のデータ
		m_block_info[block_type] = m_data_info[i];				//容器に追加
	}

	m_data_info.clear();										//ダミーデータを解放
}

vector<Grid> MapLoader::GetMapChip()
{
	return m_map_chip;
}

map<int, string> MapLoader::GetBlockDef() 
{
	return m_block_info;
}

int MapLoader::GetXSize() 
{
	return m_map_chip.size() / m_y_size;					//全部の数　/　Y軸の数　＝　X軸の数
}