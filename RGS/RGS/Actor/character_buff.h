//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.10
// 内容：キャラとバフにかかわる処理
//-------------------------------------------------------
#pragma once
#include <vector>
#include <memory>
#include "Buff\buff_base.h"
#include "states.h"

namespace Actor
{
	class CharacterBuff
	{
	public:
		CharacterBuff();
		~CharacterBuff();
		void Initialize();
		
		//Instant effect. Clear after update.
		void UpdateInstant();
		void AddInstant(std::shared_ptr<BuffBase> buff);

		//Buffs working with time. Update every frame while phase "wait"
		void UpdateBuff();
		void AddBuff(std::shared_ptr<BuffBase> buff);

		//時間制限がなく、キャラの状態が変えたら確認する
		void UpdatePassive();
		void AddPassive(std::shared_ptr<BuffBase> buff);

	private:
		std::vector<std::shared_ptr<BuffBase>> m_instant_list;
		std::vector<std::shared_ptr<BuffBase>> m_buff_list;
		std::vector<std::shared_ptr<BuffBase>> m_passive_list;
		States m_buff_effect;
	};
}