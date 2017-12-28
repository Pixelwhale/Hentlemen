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

		void Initialize();
		void Clear();
		void SetMap(std::vector<Grid> map_chip, int x_size);

		void Draw();

	private:
		Device::GameDevice* m_game_device;
		std::shared_ptr<Device::Renderer> m_renderer;

		std::vector<Grid> m_map_chip;

		int m_x_size;
		int m_grid_size = 10;
	};
}