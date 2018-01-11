//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.01.05
// ���e�@�F�A�C�e���x�[�X�N���X
//-------------------------------------------------------

#pragma once
#include <Device\game_device.h>

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

		int		m_count;		//�������ԃJ�E���g
		bool	m_used;			//�A�C�e�����g�p�������H

		/*	�A�C�e���K���͈�
		1:	�P��
		2:	���i�O�R�}�j
		3:	�c�i�O�R�}�j
		4:	�\��
		5:	�R���R
		s,m,b => small,middle,big(���ʁ@���A���A��)
		*/
	};
}