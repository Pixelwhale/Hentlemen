#include <Item\recovery.h>
using namespace Item;

bool Recovery::IsUsed()
{
	if (m_input->IsKeyTrigger(DIK_R)) m_used = true;
	return m_used;
}

void Recovery::Recovery_Hp()
{
	if (m_used)
	{
		m_current_hp += 10;
	}
	m_states->Set_Hp(m_current_hp);
}

void Recovery::Draw()
{
	m_renderer->DrawString("‰ñ•œƒAƒCƒeƒ€", Math::Vector2(200, 200));
}