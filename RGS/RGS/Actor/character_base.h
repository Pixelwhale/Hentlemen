//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Actor\character_states.h>
#include <Actor\character_move.h>

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(CharacterStates states, CharacterMove move) : m_states(states), m_move(move) {};
		~CharacterBase();
	protected:
		CharacterStates& m_states;
		CharacterMove& m_move;
	};
}