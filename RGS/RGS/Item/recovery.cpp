#include <Item\recovery.h>
using namespace Item;

Recovery::Recovery()
	:Item_Base(m_times,m_interval,m_delay)
{
	m_healP = 1;
	m_healF = 1;
}


void Recovery::Consume(Actor::CharacterBuff buff)
{
	//std::shared_ptr<Actor::BuffBase> 
	m_heal = std::make_shared<Actor::Heal>(m_healP, m_healF, m_times, m_interval, m_delay);
	buff.AddBuff(m_heal);
}

void Recovery::Draw()
{
	m_renderer->DrawString("‰ñ•œƒAƒCƒeƒ€", Math::Vector2(200, 200));
}