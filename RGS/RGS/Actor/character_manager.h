//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.14
// 内容　：バトルでキャラクターを管理するマネージャー
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

		///<param name = "time">単位：フレーム。始め行動するまでの時間</param>
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
