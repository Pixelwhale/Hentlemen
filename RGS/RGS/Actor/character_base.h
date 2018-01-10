//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Actor\character_states.h>
#include <Actor\character_move.h>
#include <Actor\Buff\buff_base.h>
#include <vector>
#include <memory>

namespace Actor
{
	class CharacterBase
	{
	public:
		CharacterBase(CharacterStates states, CharacterMove move) : m_states(states), m_move(move) {};
		~CharacterBase();
		void Initialize();
		void Update();
		void AddBuff(std::shared_ptr<BuffBase> buff);
	protected:
		CharacterStates& m_states;
		CharacterMove& m_move;

		std::vector<std::shared_ptr<BuffBase>> m_buff_list;
		int m_buff_effect[16];
	};
}