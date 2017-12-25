#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\content_manager.h>
#include <vector>

namespace Device
{
	class CSVReader
	{
	public:
		CSVReader();
		~CSVReader();

		void Read(std::string filename);

	private:
		std::vector<std::vector<std::string[]>> m_stringData;
	};
}