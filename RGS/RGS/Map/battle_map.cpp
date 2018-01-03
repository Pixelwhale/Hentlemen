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
	m_block_def.clear();	//Block��`���폜
	m_x_size = 0;			//�}�b�v�̑傫�������폜
	m_map_size = 0;			//�}�b�v�̑傫�������폜
}

void BattleMap::SetMap(std::vector<Grid> map_chip, int x_size)
{
	m_map_chip = map_chip;				//MapChip�ݒ�
	m_x_size = x_size;					//X���̐����w��
	m_map_size = m_map_chip.size();		//�}�b�v�̑傫����ݒ�
}

void BattleMap::SetBlock(std::map<int, std::string> block_def)
{
	m_block_def = block_def;			//Block��`�ݒ�
}

void BattleMap::MapInfo(int x, int y, int& height)
{
	int index = y * m_x_size + x;			//Index�v�Z
	if (index >= m_map_size)				//��O����
	{
		height = -1;
		return;
	}

	height = m_map_chip[index].Height();	//������ݒ�
}

void BattleMap::Draw()
{
	for (int i = 0; i < m_map_size; i++)							//�}�X�̂��������J��Ԃ�
	{
		for (int j = 0; j < m_map_chip[i].blocks.size(); j++)		//�����̂��������J��Ԃ�
		{
			int block_type = m_map_chip[i].blocks[j];				//Block�̎�ނ��擾
			SetTexture(block_type);									//Texture��ݒ�

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

void BattleMap::SetTexture(int block_type)
{
	if (m_block_def[block_type] == "default")							//Default�̏ꍇ
	{
		m_renderer->ResetModelTexture("test_block");					//����Texture���g�p
		return;
	}

	m_renderer->SetModelTexture("test_block", m_block_def[block_type]);	//��`�̃e�N�X�`���[�g�p
}
