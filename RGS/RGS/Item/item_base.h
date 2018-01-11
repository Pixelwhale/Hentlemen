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

		bool	m_used;			//アイテムを使用したか？
		int		m_range;		//回復範囲
		int		m_count;		//発動間隔
		int		m_times;		//発動次数
		
	};
}