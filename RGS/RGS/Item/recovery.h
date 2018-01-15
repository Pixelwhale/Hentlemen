//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.06
// 内容　：回復アイテムクラス
//-------------------------------------------------------

#pragma once
#include <Item\item_base.h>
#include <Device\game_device.h>
#include <Actor\Buff\heal.h>

namespace Item
{
	class Recovery : public Item_Base
	{
	public:
		Recovery();
		void Draw();
		void Consume(Actor::CharacterBuff buff);

	private:
		std::shared_ptr<Actor::BuffBase>	m_heal;
		int									m_healP;
		int									m_healF;
	};

}