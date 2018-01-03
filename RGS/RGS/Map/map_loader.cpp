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
	m_data_info.clear();	//�_�~�[�f�[�^�����
	m_map_chip.clear();		//�_�~�[�f�[�^�����
	m_block_info.clear();	//�_�~�[�f�[�^�����
	m_y_size = 0;			//Y���̒l��Reset
}

void MapLoader::Load(string map_file_name, string block_file_name)
{
	ReadMapData(map_file_name);

	SetupMapData();
	
	ReadBlockData(block_file_name);

	SetupBlockData();
}

void MapLoader::ReadMapData(string file_name)
{
	ifstream file_stream(file_name.c_str(), ios::in);		//�t�@�C���X�g���[��
	string input_string;									//�ǂݎ��String�̕ϐ�

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

		m_data_info.push_back(input_string);				//�����f�[�^��ۑ�
	}

	file_stream.close();									//�t�@�C�������
}

void MapLoader::SetupMapData() 
{
	m_map_chip.clear();										//�_�~�[�f�[�^�����

	for (auto& grid_info : m_data_info)						//�ǂݎ���������f�[�^���������
	{
		vector<int> blocks;									//��}�X�̏��
		for (auto& height_info : grid_info)
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

	m_data_info.clear();									//�_�~�[�f�[�^�����
}

void MapLoader::ReadBlockData(std::string file_name) 
{
	ifstream file_stream(file_name.c_str(), ios::in);		//�t�@�C���X�g���[��
	string input_string;									//�ǂݎ��String�̕ϐ�

	while (getline(file_stream, input_string, '\n'))		//��s���ǂݎ��\n�Ő؂�iSplit�j
	{
		if (input_string.length() == 0)						//���������ĂȂ������ꍇ
			continue;										//�X�L�b�v
		
		int erase_chara = 1;								//�폜���镶����
		string type_data = "";								//BlockType
		string asset_data = "";								//Texture��

		for (auto& character : input_string) 
		{
			if (character == ',')							//,��Split
			{
				input_string.erase(0, erase_chara);			//�c�����f�[�^
				asset_data = input_string;
				break;
			}

			type_data += character;							//�擪�f�[�^�ǉ�
			++erase_chara;
		}

		m_data_info.push_back(type_data);					//Type�f�[�^��ۑ�
		m_data_info.push_back(asset_data);					//Texture�f�[�^��ۑ�
	}

	file_stream.close();									//�t�@�C�������
}

void MapLoader::SetupBlockData() 
{
	m_block_info.clear();										//�_�~�[�f�[�^�����

	for (unsigned int i = 0; i < m_data_info.size(); ++i) 
	{
		int block_type = 0;
		sscanf_s(m_data_info[i].c_str(), "%d", &block_type);	//BlockType��int�ɕϊ�

		++i;													//���̃f�[�^
		m_block_info[block_type] = m_data_info[i];				//�e��ɒǉ�
	}

	m_data_info.clear();										//�_�~�[�f�[�^�����
}

vector<Grid> MapLoader::GetMapChip()
{
	return m_map_chip;
}

map<int, string> MapLoader::GetBlockDef() 
{
	return m_block_info;
}

int MapLoader::GetXSize() 
{
	return m_map_chip.size() / m_y_size;					//�S���̐��@/�@Y���̐��@���@X���̐�
}