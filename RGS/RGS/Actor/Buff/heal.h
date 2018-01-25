//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.09
//-------------------------------------------------------
#pragma once
#include "buff_base.h"

namespace Actor
{
	class Heal : public BuffBase
	{
	public:
		Heal(int healF, float healP, int times, int interval, int delay);
	private:
		void Effect(BuffFunction& sbattle);
		int m_healF;
		float m_healP;
	};
}