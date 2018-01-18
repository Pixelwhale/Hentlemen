//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include "states.h"
#include "character_move.h"
#include "character_buff.h"
#include "Buff\buff_base.h"
#include <Math/vector3.h>

namespace Actor
{
	class CharacterBase
	{
	public:
		//(player)
		CharacterBase(int id, States states);

		//(enemy)
		//read file and set states by id
		CharacterBase(int id);

		~CharacterBase();

		//full recovery
		//add passives to character_buff
		void Initialize();

		void Update();

		bool IsDead();

	protected:
		int m_id;
		States m_battle;		//battle states
		CharacterMove m_move;
		CharacterBuff m_buff;
	};
}