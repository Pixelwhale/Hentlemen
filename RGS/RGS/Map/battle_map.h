//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�FMapChip�̕ۑ��ƕ\��
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Map\map_grid.h>
#include <vector>

namespace Map
{
	class BattleMap
	{
	public:
		BattleMap();
		BattleMap(const BattleMap&);
		~BattleMap();

		///<summary>�����������iDevice�n���擾�j</summary>
		void Initialize();
		///<summary>�}�b�v�����폜</summary>
		void Clear();

		///<summary>�}�b�v����ݒ�</summary>
		///<param name="map_chip">�}�b�v�`�b�v</param>
		///<param name="x_size">X���̃}�X�ڑ���</param>
		void SetMap(std::vector<Grid> map_chip, int x_size);
		///<summary>�u���b�N����ݒ�</summary>
		///<param name="block_def">�u���b�N���</param>
		void SetBlock(std::map<int, std::string> block_def);

		///<summary>�}�b�v�����擾</summary>
		///<param name="x">X�}�X</param>
		///<param name="y">Y�}�X</param>
		///<param name="height">����</param>
		void MapInfo(int x, int y, int& height);

		///<summary>�}�b�v��`��</summary>
		void Draw();

	private:
		///<summary>BlockTexture��ϊ�</summary>
		void SetTexture(int block_type);

	private:
		Device::GameDevice* m_game_device;					//GameDevice
		std::shared_ptr<Device::Renderer> m_renderer;		//�`��pRenderer

		std::vector<Grid> m_map_chip;						//MapChip�̏��
		std::map<int, std::string> m_block_def;				//Block��`

		int m_map_size;										//�}�b�v�̑傫��
		int m_x_size;										//X���̃}�X�ڑ���
		int m_grid_size = 10;								//Model�̃T�C�Y�i��}�X�̃T�C�Y�j
	};
}