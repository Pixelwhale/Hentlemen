//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�FMapChip���t�@�C������ǂݍ���
//-------------------------------------------------------
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
	m_map_chip.clear();		//�_�~�[�f�[�^�����
	m_y_size = 0;			//Y���̒l��Reset
}

void MapLoader::Load(string file_name)
{
	ifstream file_stream(file_name.c_str(), ios::in);		//�t�@�C���X�g���[��
	string input_string;									//�ǂݎ��String�̕ϐ�
	vector<string> map_info;								//�ǂݎ����������ۑ�����e��

	m_y_size = 0;											//�T�C�Y�����Z�b�g

	while (getline(file_stream, input_string, '"'))			//��s���ǂݎ��@"�Ő؂�iSplit�j
	{
		if (input_string.length() == 0 ||					//���������ĂȂ������ꍇ
			input_string[0] == ',')							//�ŏ���,�̏ꍇ
			continue;										//�X�L�b�v

		if (input_string == "\n")							//���s�L��
		{
			++m_y_size;										//�s�����X�V�iY���ɒǉ��j
			continue;										//�ۑ����Ȃ�
		}

		map_info.push_back(input_string);					//�����f�[�^��ۑ�
	}

	file_stream.close();									//�t�@�C�������

	for (auto& grid_info:map_info)							//�ǂݎ���������f�[�^���������
	{
		vector<int> blocks;									//��}�X�̏��
		for (auto& height_info:grid_info)
		{
			if (height_info == ' ' ||						//�󗓁A��؂�͖���
				height_info == ',')
				continue;
			if (height_info == 'N')							//Null��N�ɗ����玟�̃}�X��
				break;

			blocks.push_back(height_info - '0');			//�}�X����ǉ��i�����Ƃ��āj
		}

		Grid grid(blocks);									//��}�X�̏��𐶐�
		m_map_chip.push_back(grid);							//�}�b�v���ɒǉ�
	}
}

std::vector<Grid> MapLoader::GetMapChip()
{
	return m_map_chip;
}

int MapLoader::GetXSize() 
{
	return m_map_chip.size() / m_y_size;					//�S���̐��@/�@Y���̐��@���@X���̐�
}