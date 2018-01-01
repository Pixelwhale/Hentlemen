//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�FMapChip�̕ۑ��ƕ\��
//-------------------------------------------------------
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
	m_game_device = Device::GameDevice::GetInstance();		//GameDevice�̎��̂��擾
	m_renderer = m_game_device->GetRenderer();				//Renderer�̎��̂��擾
}

void BattleMap::Clear() 
{
	m_map_chip.clear();		//�}�b�v�����폜
	m_x_size = 0;			//�}�b�v�̑傫�������폜
}

void BattleMap::SetMap(std::vector<Grid> map_chip, int x_size) 
{
	m_map_chip = map_chip;	//MapChip�ݒ�
	m_x_size = x_size;		//X���̐����w��
}


void BattleMap::Draw()
{
	for (int i = 0; i < m_map_chip.size(); i++)						//�}�X�̂��������J��Ԃ�
	{
		for (int j = 0; j < m_map_chip[i].blocks.size(); j++)		//�����̂��������J��Ԃ�
		{
			if (j == m_map_chip[i].blocks.size() - 1)				//Test�@�\Texture�������ւ�
			{
				m_renderer->ResetModelTexture("test_block");
			}
			else
			{
				m_renderer->SetModelTexture("test_block", "block_ground");
			}

			int x = i % m_x_size;		//X���W�iX���̐������������܂�j
			int y = i / m_x_size;		//X���W�iX���̐������������l�j
			m_renderer->DrawModel(
				"test_block",
				Math::Vector3(x * m_grid_size, j * m_grid_size, -y * m_grid_size),	//�ʒu
				Math::Vector3(m_grid_size, m_grid_size, m_grid_size),				//�傫��
				Math::Vector3(0, 0, 0));											//��]
		}
	}
}
