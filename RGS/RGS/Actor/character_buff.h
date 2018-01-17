//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.10
// 内容：キャラとバフにかかわる処理
//-------------------------------------------------------
#pragma once
#include <vector>
#include <memory>
#include <Actor\Buff\buff_base.h>

namespace Actor
{
	class CharacterBuff
	{
	public:
		CharacterBuff();
		~CharacterBuff();
		void Initialize();
		
		//instant effect
		void UpdateInstant();
		void AddInstant(std::shared_ptr<BuffBase> buff);

		//not instant effect. Update every frame while phase "wait"
		void UpdateBuff();
		void AddBuff(std::shared_ptr<BuffBase> buff);

		//時間制限がなく、キャラの状態が変えたら確認する
		void UpdatePassive();
		void AddPassive(std::shared_ptr<BuffBase> buff);

	private:
		std::vector<std::shared_ptr<BuffBase>> m_instant_list;
		std::vector<std::shared_ptr<BuffBase>> m_buff_list;
		std::vector<std::shared_ptr<BuffBase>> m_passive_list;
		int m_buff_effect[16]{ 0 };
	};
}