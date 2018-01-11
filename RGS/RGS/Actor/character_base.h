//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Actor\character_states.h>
#include <Actor\character_move.h>
#include <Actor\character_buff.h>
#include <Actor\Buff\buff_base.h>

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(CharacterStates states) : m_states(states) {};
		~CharacterBase();
		void Initialize();
		void Update();
	protected:
		CharacterStates& m_states;
		CharacterMove m_move;
		CharacterBuff m_buff;
	};
}