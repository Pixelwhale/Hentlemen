//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.12.15
//-------------------------------------------------------
#include <Actor\Buff\buff_base.h>

using namespace Actor;

BuffBase::BuffBase()
{
	m_times = 1;
	m_interval = 0;
	m_timer = 0;
	m_is_instant = true;
	m_is_end = false;
}

BuffBase::BuffBase(int times, int interval, int delay)
{
	m_times = times;
	m_interval = interval;
	m_timer = delay;
	m_is_instant = false;
	m_is_end = false;
}

BuffBase::~BuffBase()
{
}

void BuffBase::Update()
{
	if (m_is_end == true) return;

	m_timer--;
	if (m_timer <= 0)
	{
		m_timer = m_interval;
		m_times--;
		if (m_times == 0) m_is_end = true;
		Effect();
	}
}