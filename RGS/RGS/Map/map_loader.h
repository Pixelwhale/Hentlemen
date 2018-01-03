//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�FMapChip���t�@�C������ǂݍ���
//-------------------------------------------------------
#pragma once
#include <string>
#include <vector>
#include <map>
#include <Map\map_grid.h>

namespace Map 
{
	class MapLoader 
	{
	public:
		MapLoader();
		MapLoader(const MapLoader&);
		~MapLoader();

		///<summary>�ǂݍ��񂾃_�~�[�f�[�^���폜</summary>
		void Clear();
		///<summary>�t�@�C������f�[�^��ǂݍ���</summary>
		///<param name="map_file_name">�}�b�v�̃t�@�C����</param>
		///<param name="block_file_name">�Ή�����u���b�N�̃t�@�C����</param>
		void Load(std::string map_file_name, std::string block_file_name);

		///<summary>�}�b�v�`�b�v���擾</summary>
		std::vector<Grid> GetMapChip();
		///<summary>�}�b�v�`�b�v��X���̐�</summary>
		int GetXSize();

		std::map<int, std::string> GetBlockDef();

	private:
		///<summary>�t�@�C������}�b�v����ǂݎ��</summary>
		void ReadMapData(std::string file_name);
		///<summary>�ǂݎ�����f�[�^���}�b�v���ɐݒ�</summary>
		void SetupMapData();
		///<summary>�t�@�C������u���b�N����ǂݎ��</summary>
		void ReadBlockData(std::string file_name);
		///<summary>�ǂݎ�����f�[�^���u���b�N���ɐݒ�</summary>
		void SetupBlockData();

	private:
		std::vector<std::string> m_data_info;		//�ǂݎ����������ۑ�����e��

		std::vector<Grid> m_map_chip;				//�}�b�v�`�b�v
		int m_y_size;								//Y���̐�

		std::map<int, std::string> m_block_info;	//Block��`
	};
}