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
		CharacterMove(int move, int jump);
		~CharacterMove();

	private:
		int m_move;		//�ړ��́B�����Ȃ�ƈړ����鎞������
		int m_jump;
	};
}