//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.15
// ���e�@�F�o�t�ƃf�o�t�̏���
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class BuffBase
	{
	public:
		///<param name = "duration">�P�ʁF�b�B��񂵂��Ȃ����ʂ�0</param>
		BuffBase(float duration);
		~BuffBase();
		void Update();
	protected:
		float m_duration;
	};
}