//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once
#include "character_base.h"

namespace Actor
{
	class Player : public CharacterBase
	{
	public:
		Player(int id) : CharacterBase(id) {};

		//check if load mode / save file exist
		//if not, read file and set basis states
		void Initialize();

		//(player)calculate battle states with basis states and passive states
		//(both)add passives to character_buff
		void BattleInitialize();

	private:
		States m_base_states;
	};
}