//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.05
// 内容　：アイテムベースクラス
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

		int		m_count;		//持続時間カウント
		bool	m_used;			//アイテムを使用したか？

		/*	アイテム適応範囲
		1:	単体
		2:	横（三コマ）
		3:	縦（三コマ）
		4:	十字
		5:	３＊３
		s,m,b => small,middle,big(効果　小、中、大)
		*/
	};
}