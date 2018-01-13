//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.15
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class BuffBase
	{
	public:
		///<summary>�������ʂ���������o�t</summary>
		BuffBase();
		///<param name = "times">���ʔ��������</param>
		///<param name = "interval">�P�ʁF�t���[���B���ʂƌ��ʂ̊�</param>
		///<param name = "delay">�P�ʁF�t���[���B�o�t����邩��A���߂Č��ʂ���������܂ł̎���</param>
		BuffBase(int times, int interval, int delay);
		~BuffBase();

		//���ԈȊO�̔����������K�v�Ȃ�I�[�o�[���C�h
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