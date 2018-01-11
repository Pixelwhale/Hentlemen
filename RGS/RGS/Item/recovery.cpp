#include <Item\recovery.h>
using namespace Item;

bool Recovery::IsUsed()
{
	if (m_input->IsKeyTrigger(DIK_R)) m_used = true;
	return m_used;
}


void Recovery::Draw()
{
	m_renderer->DrawString("回復アイテム", Math::Vector2(200, 200));
}