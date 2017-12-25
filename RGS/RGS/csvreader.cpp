#include <csvreader.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace Device;

Device::CSVReader::CSVReader()
{
	m_stringData.clear();
}

void Device::CSVReader::Read(std::string filename)
{
	std::ifstream ip(filename);

	if (!ip.is_open()) std::cout << "Error : File Open" << '\n';

	std::string segment;
	while (std::getline(ip, segment))
	{
		std::istringstream iss(segment);
		// ���͂ǂ������Ă���̂��H���̃v���O�����̃`�F�b�N������@����������Ȃ��āA���߂�Ȃ����B
	}
}


