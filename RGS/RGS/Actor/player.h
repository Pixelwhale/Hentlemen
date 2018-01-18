//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once
#include "states.h"

namespace Actor
{
	class Player
	{
	public:
		//read file and set basis states; 
		//check if load mode / save data exist, if yes, basis += save data
		Player(int id);

		//(player)calculate battle states with basis states and passive states
		States BattleStates();

	private:
		//save level and attributed states
		States m_basis;
	};
}