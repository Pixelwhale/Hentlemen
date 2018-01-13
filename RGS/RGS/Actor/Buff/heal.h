//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.09
//-------------------------------------------------------
#pragma once
#include <Actor\Buff\buff_base.h>

namespace Actor
{
	class Heal : public BuffBase
	{
	public:
		Heal(int healP, int healF);
		Heal(int healP, int healF, int times, int interval, int delay);
	private:
		void Effect();
		int m_healP;
		int m_healF;
	};
}