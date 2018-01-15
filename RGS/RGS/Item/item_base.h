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
#include <Actor\character_base.h>

namespace Item
{
	class Item_Base
	{
	public:
		Item_Base(int times, int interval, int delay);
		virtual ~Item_Base();
		virtual void Consume(Actor::CharacterBuff buff) = 0;

	protected:
		std::shared_ptr<Device::Renderer> m_renderer;
		std::shared_ptr<Core::InputState> m_input;

		int		m_times;		
		int		m_interval;
		int		m_delay;
		
	};
}