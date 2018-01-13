//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.15
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class BuffBase
	{
	public:
		///<summary>すぐ効果が発生するバフ</summary>
		BuffBase();
		///<param name = "times">効果発生する回数</param>
		///<param name = "interval">単位：フレーム。効果と効果の間</param>
		///<param name = "delay">単位：フレーム。バフが取るから、初めて効果が発生するまでの時間</param>
		BuffBase(int times, int interval, int delay);
		~BuffBase();

		//時間以外の発動条件が必要ならオーバーライド
		virtual void Update();

		bool IsInstant() { return m_is_instant; }

	protected:
		virtual void Effect() = 0;
		int m_times;
		int m_interval;
		int m_timer;
		int m_is_instant;
		int m_is_end;
	};
}