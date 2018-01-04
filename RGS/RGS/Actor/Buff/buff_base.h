//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.15
// 内容　：バフとデバフの処理
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class BuffBase
	{
	public:
		///<param name = "duration">単位：秒。一回しかない効果は0</param>
		BuffBase(float duration);
		~BuffBase();
		void Update();
	protected:
		float m_duration;
	};
}