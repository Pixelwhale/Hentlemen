//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.06
// 内容　：回復アイテムクラス
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
		bool	m_used;			//アイテムを使用したか？
	};

}