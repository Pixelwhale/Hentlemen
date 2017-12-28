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
	m_game_device = Device::GameDevice::GetInstance();
	m_renderer = m_game_device->GetRenderer();
	//for (int i = 0; i < 49; i++)
	//{
	//	int height = m_game_device->GetRandom()->Next(1, 5);
	//	std::vector<int> blocks;
	//	for (int j = 0; j < height; j++)
	//	{
	//		blocks.push_back(1);
	//	}

	//	m_map_chip.push_back(Grid(blocks));
	//}
}

void BattleMap::Clear() 
{
	m_map_chip.clear();
	m_x_size = 0;
}

void BattleMap::SetMap(std::vector<Grid> map_chip, int x_size) 
{
	m_map_chip = map_chip;
	m_x_size = x_size;
}


void BattleMap::Draw()
{
	for (int i = 0; i < m_map_chip.size(); i++)
	{
		for (int j = 0; j < m_map_chip[i].blocks.size(); j++)
		{
			int x = i % m_x_size;
			int y = i / m_x_size;
			m_renderer->DrawModel(
				"test",
				Math::Vector3(x * m_grid_size, j * m_grid_size, y * m_grid_size),
				Math::Vector3(m_grid_size, m_grid_size, m_grid_size),
				Math::Vector3(0, 0, 0));
		}
	}
}
