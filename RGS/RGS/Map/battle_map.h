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

		///<summary>�}�b�v��`��</summary>
		void Draw();

	private:
		Device::GameDevice* m_game_device;					//GameDevice
		std::shared_ptr<Device::Renderer> m_renderer;		//�`��pRenderer

		std::vector<Grid> m_map_chip;						//MapChip�̏��

		int m_x_size;										//X���̃}�X�ڑ���
		int m_grid_size = 10;								//Model�̃T�C�Y�i��}�X�̃T�C�Y�j
	};
}