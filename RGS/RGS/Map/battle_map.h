//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.28
// 内容　：MapChipの保存と表示
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Map\map_grid.h>
#include <vector>

namespace Map
{
	class BattleMap
	{
	public:
		BattleMap();
		BattleMap(const BattleMap&);
		~BattleMap();

		///<summary>初期化処理（Device系を取得）</summary>
		void Initialize();
		///<summary>マップ情報を削除</summary>
		void Clear();

		///<summary>マップ情報を設定</summary>
		///<param name="map_chip">マップチップ</param>
		///<param name="x_size">X軸のマス目総数</param>
		void SetMap(std::vector<Grid> map_chip, int x_size);

		///<summary>マップを描画</summary>
		void Draw();

	private:
		Device::GameDevice* m_game_device;					//GameDevice
		std::shared_ptr<Device::Renderer> m_renderer;		//描画用Renderer

		std::vector<Grid> m_map_chip;						//MapChipの情報

		int m_x_size;										//X軸のマス目総数
		int m_grid_size = 10;								//Modelのサイズ（一マスのサイズ）
	};
}