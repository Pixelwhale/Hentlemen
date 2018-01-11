//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.01.05
// 内容　：アイテムベースクラス
//-------------------------------------------------------

#include "item_base.h"

using namespace Item;
using namespace Device;
using namespace Actor;

Item_Base::Item_Base(Actor::CharacterStates* states) :m_states(states)
{
	m_renderer = GameDevice::GetInstance()->GetRenderer();
	m_input = GameDevice::GetInstance()->GetInput();
	m_current_hp = m_states->Get_Hp();
	m_current_ap = m_states->Get_Ap();
	m_str = m_states->Get_Str();
	m_con = m_states->Get_Con();
	m_dex = m_states->Get_Dex();
	m_agi = m_states->Get_Agi();
	m_int = m_states->Get_Int();
	m_wis = m_states->Get_Wis();
}

Item_Base::~Item_Base()
{
	
}