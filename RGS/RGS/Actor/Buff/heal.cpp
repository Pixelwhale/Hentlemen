//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.09
//-------------------------------------------------------
#include <Actor\Buff\heal.h>

using namespace Actor;

Heal::Heal(int healP, int healF, int times, int interval, int delay)
	: BuffBase(times, interval, delay)
{
	m_healP = healP;
	m_healF = healF;
}

void Heal::Effect()
{

}