//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.09
// ���e�@�FPassive Skill
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