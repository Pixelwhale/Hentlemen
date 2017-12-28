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

		void Clear();
		void Load(std::string file_name);

		std::vector<Grid> GetMapChip();
		int GetXSize();

	private:
		std::vector<Grid> m_map_chip;
		int m_y_size;
	};
}