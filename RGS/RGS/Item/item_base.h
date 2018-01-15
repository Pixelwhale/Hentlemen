//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.05
// 内容　：アイテムベースクラス
//-------------------------------------------------------
/*	アイテム説明
アイテム適応範囲
1:	単体
2:	横（三コマ）
3:	縦（三コマ）
4:	十字
5:	３＊３

a,b,c => 効果　小、中、大
int => 実数
per => パーセント
cnt => 持続効果を持つアイテム
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