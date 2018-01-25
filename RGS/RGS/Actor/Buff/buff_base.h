//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.15
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
		///<param name = "times">効果発生する回数</param>
		///<param name = "interval">単位：フレーム。効果と効果の間</param>
		///<param name = "delay">単位：フレーム。バフが取るから、初めて効果が発生するまでの時間</param>
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