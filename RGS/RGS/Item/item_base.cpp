//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.05
// 内容　：アイテムベースクラス
//-------------------------------------------------------

#include "item_base.h"

using namespace Item;
using namespace Device;
using namespace Actor;

Item_Base::Item_Base()
{
	m_renderer = GameDevice::GetInstance()->GetRenderer();
	m_input = GameDevice::GetInstance()->GetInput();
	
}

Item_Base::~Item_Base()
{
	
}