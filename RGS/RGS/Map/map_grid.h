#pragma once
#include <vector>

namespace Map
{
	struct Grid
	{
		Grid(std::vector<int> height)
		{
			blocks = height;
		}

		int Height() { return blocks.size(); }

		std::vector<int> blocks;
	};
}