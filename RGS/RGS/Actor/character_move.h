//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.14
// ���e�@�F�L�����N�^�[�̈ړ��ɂ��ď���
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class CharacterMove
	{
	public:
		CharacterMove(int move);
		~CharacterMove();

	private:
		int Move();			//AP-=5000/Move;
		int m_base_move;
	};
}