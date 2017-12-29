//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�FMapChip���t�@�C������ǂݍ���
//-------------------------------------------------------
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

		///<summary>�ǂݍ��񂾃_�~�[�f�[�^���폜</summary>
		void Clear();
		///<summary>�t�@�C������f�[�^��ǂݍ���</summary>
		void Load(std::string file_name);

		///<summary>�}�b�v�`�b�v���擾</summary>
		std::vector<Grid> GetMapChip();
		///<summary>�}�b�v�`�b�v��X���̐�</summary>
		int GetXSize();

	private:
		std::vector<Grid> m_map_chip;		//�}�b�v�`�b�v
		int m_y_size;						//Y���̐�
	};
}