//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.15
//-------------------------------------------------------
#pragma once
#include "../character_base.h"

namespace Actor
{
	enum BuffType
	{
		kDamage,
		kHeal,
		kStates,
	};

	enum Source
	{
		kBurning,
		kPoison,
	};

	class BuffBase
	{
	public:
		///<param name = "times">���ʔ��������</param>
		///<param name = "interval">�P�ʁF�t���[���B���ʂƌ��ʂ̊�</param>
		///<param name = "delay">�P�ʁF�t���[���B�o�t����邩��A���߂Č��ʂ���������܂ł̎���</param>
		BuffBase(int times, int interval, int delay);
		~BuffBase();

		virtual void Update(BuffFunction& sbattle);

		BuffType GetType() { return m_type; }
		
		//buff type == states
		virtual void CountStates(States& sbuff, States& sdebuff) = 0;

	protected:
		virtual void Effect(BuffFunction& sbattle) = 0;
		BuffType m_type;
		int m_times;
		int m_interval;
		int m_timer;
		bool m_is_end;
	};
}