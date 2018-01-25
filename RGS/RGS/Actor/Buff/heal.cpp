//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.09
//-------------------------------------------------------
#include <Actor\Buff\heal.h>

using namespace Actor;

Heal::Heal(int healF, float healP, int times, int interval, int delay)
	: BuffBase(times, interval, delay)
{
	m_healP = healP;
	m_healF = healF;
	m_type = kHeal;
}

void Heal::Effect(BuffFunction& sbattle)
{
	sbattle.Heal(m_healF, m_healP);
}