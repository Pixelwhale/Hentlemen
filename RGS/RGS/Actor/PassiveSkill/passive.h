//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.09
// 内容　：Passive Skill
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class Passive
	{
	public:
		Passive();
		~Passive();
		void Initialize();
	private:
		int m_passive[16];
	};
}