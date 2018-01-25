//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.12.15
//-------------------------------------------------------
#include <Actor\Buff\buff_base.h>

using namespace Actor;

BuffBase::BuffBase(int times, int interval, int delay)
{
	m_times = times;
	m_interval = interval;
	m_timer = delay;
	m_is_end = false;
}

BuffBase::~BuffBase()
{
}

void BuffBase::Update(BuffFunction& sbattle)
{
	if (m_is_end == true) return;

	m_timer--;
	if (m_timer <= 0)
	{
		m_timer = m_interval;
		m_times--;
		if (m_times == 0) m_is_end = true;
		Effect(sbattle);
	}
}
