//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F���[�_�[�̃x�[�X�V�[��
//-------------------------------------------------------
#include <Device\loader.h>

using namespace Device;

Loader::~Loader()
{
	m_resources.clear();
}

void Loader::Initialize()
{
	m_max_num = 0;
	m_counter = 0;
	m_end_flag = false;
	if (m_resources[0] != NULL)
	{
		m_max_num = m_resources.size();
	}
}