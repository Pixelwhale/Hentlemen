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
	m_map_chip.clear();
	m_y_size = 0;
}

void MapLoader::Load(string file_name)
{
	ifstream file_stream(file_name.c_str(), ios::in);
	string input_string;
	vector<string> map_info;

	m_y_size = 0;

	while (getline(file_stream, input_string, '"'))
	{
		if (input_string.length() == 0 || 
			input_string[0] == ',')
			continue;

		if (input_string == "\n")
		{
			++m_y_size;
			continue;
		}

		map_info.push_back(input_string);
	}

	file_stream.close();

	for (auto& grid_info:map_info) 
	{
		vector<int> blocks;
		for (auto& height_info:grid_info)
		{
			if (height_info == ' ' ||
				height_info == ',')
				continue;
			if (height_info == 'N')
				break;

			blocks.push_back(height_info - '0');
		}

		Grid grid(blocks);
		m_map_chip.push_back(grid);
	}
}

std::vector<Grid> MapLoader::GetMapChip()
{
	return m_map_chip;
}

int MapLoader::GetXSize() 
{
	return m_map_chip.size() / m_y_size;
}