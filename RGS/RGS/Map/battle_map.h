#pragma once
#include <Device\game_device.h>
#include <vector>

namespace Map
{
	struct Grid
	{
		Grid(int height[]) 
		{
			for (int i = 0; i < sizeof(height); i++) 
			{
				if (height[i] == 0)
					continue;
				blocks.push_back(height[i]);
			}
		}

		int Height() { return blocks.size(); }
		
		std::vector<int> blocks;
	};


	class BattleMap
	{
	public:
		BattleMap();
		BattleMap(const BattleMap&);
		~BattleMap();

		void Initialize();

		void Draw();



	private:
		Device::GameDevice* m_game_device;
		std::shared_ptr<Device::Renderer> m_renderer;
		std::vector<Grid> m_map_chip;

		int m_x_size = 5;
		int m_grid_size = 10;
	};
}