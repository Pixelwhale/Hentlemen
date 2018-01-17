//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.14
// ���e�@�F�o�g���ŃL�����N�^�[���Ǘ�����}�l�[�W���[
//-------------------------------------------------------
#pragma once
#include "character_base.h"
#include "Buff\buff_base.h"
#include <vector>
#include <memory>

namespace Actor
{
	class CharacterManager
	{
	public:
		CharacterManager();
		void Initialize();
		void Update();

		///<param name = "time">�P�ʁF�t���[���B�n�ߍs������܂ł̎���</param>
		void AddCharacter(std::shared_ptr<CharacterBase>, int time);

	private:

		struct BattleChara
		{
			BattleChara(std::shared_ptr<CharacterBase> c, int time) : c(c), time(time) {};
			std::shared_ptr<CharacterBase> c;
			int time;
		};

		std::vector<BattleChara> m_character_list;
	};
}
