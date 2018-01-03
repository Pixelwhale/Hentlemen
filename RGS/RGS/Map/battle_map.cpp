//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：MapChipの保存と表示
//-------------------------------------------------------
#include <Map\battle_map.h>

using namespace Map;

BattleMap::BattleMap()
{
}

BattleMap::BattleMap(const BattleMap&)
{
}

BattleMap::~BattleMap()
{
}


void BattleMap::Initialize()
{
	m_game_device = Device::GameDevice::GetInstance();		//GameDeviceの実体を取得
	m_renderer = m_game_device->GetRenderer();				//Rendererの実体を取得
}

void BattleMap::Clear()
{
	m_map_chip.clear();		//マップ情報を削除
	m_block_def.clear();	//Block定義を削除
	m_x_size = 0;			//マップの大きさ情報を削除
	m_map_size = 0;			//マップの大きさ情報を削除
}

void BattleMap::SetMap(std::vector<Grid> map_chip, int x_size)
{
	m_map_chip = map_chip;				//MapChip設定
	m_x_size = x_size;					//X軸の数を指定
	m_map_size = m_map_chip.size();		//マップの大きさを設定
}

void BattleMap::SetBlock(std::map<int, std::string> block_def)
{
	m_block_def = block_def;			//Block定義設定
}

void BattleMap::MapInfo(int x, int y, int& height)
{
	int index = y * m_x_size + x;			//Index計算
	if (index >= m_map_size)				//例外処理
	{
		height = -1;
		return;
	}

	height = m_map_chip[index].Height();	//高さを設定
}

void BattleMap::Draw()
{
	for (int i = 0; i < m_map_size; i++)							//マスのある限りを繰り返す
	{
		for (int j = 0; j < m_map_chip[i].blocks.size(); j++)		//高さのある限りを繰り返す
		{
			int block_type = m_map_chip[i].blocks[j];				//Blockの種類を取得
			SetTexture(block_type);									//Textureを設定

			int x = i % m_x_size;		//X座標（X軸の数を割ったあまり）
			int y = i / m_x_size;		//X座標（X軸の数を割った数値）
			m_renderer->DrawModel(
				"test_block",
				Math::Vector3(x * m_grid_size, j * m_grid_size, -y * m_grid_size),	//位置
				Math::Vector3(m_grid_size, m_grid_size, m_grid_size),				//大きさ
				Math::Vector3(0, 0, 0));											//回転
		}
	}
}

void BattleMap::SetTexture(int block_type)
{
	if (m_block_def[block_type] == "default")							//Defaultの場合
	{
		m_renderer->ResetModelTexture("test_block");					//元のTextureを使用
		return;
	}

	m_renderer->SetModelTexture("test_block", m_block_def[block_type]);	//定義のテクスチャー使用
}
