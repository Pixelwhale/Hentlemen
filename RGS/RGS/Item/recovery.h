//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.01.06
// ���e�@�F�񕜃A�C�e���N���X
//-------------------------------------------------------

#pragma once
#include <Item\item_base.h>
#include <Device\game_device.h>

namespace Item
{
	class Recovery : public Item_Base
	{
	public:
		bool IsUsed();
		void Recovery_Hp();
		void Draw();

	private:
		bool	m_used;			//�A�C�e�����g�p�������H
	};

}