//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.01.05
// ���e�@�F�A�C�e���x�[�X�N���X
//-------------------------------------------------------
/*	�A�C�e������
�A�C�e���K���͈�
1:	�P��
2:	���i�O�R�}�j
3:	�c�i�O�R�}�j
4:	�\��
5:	�R���R

a,b,c => ���ʁ@���A���A��
int => ����
per => �p�[�Z���g
cnt => �������ʂ����A�C�e��
*/

#pragma once
#include <Device\game_device.h>
#include <Actor\Buff\buff_base.h>

namespace Item
{
	class Item_Base
	{
	public:
		Item_Base();
		virtual ~Item_Base();

	protected:
		std::shared_ptr<Device::Renderer> m_renderer;
		std::shared_ptr<Core::InputState> m_input;

		bool	m_used;			//�A�C�e�����g�p�������H
		int		m_range;		//�񕜔͈�
		int		m_count;		//�����Ԋu
		int		m_times;		//��������
		
	};
}