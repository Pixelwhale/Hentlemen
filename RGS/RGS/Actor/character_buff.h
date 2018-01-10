//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.01.10
// 内容：キャラとバフにかかわる処理
//-------------------------------------------------------
#pragma once
#include <vector>
#include <memory>
#include <Actor\Buff\buff_base.h>

namespace Actor {
	class CharacterBuff
	{
	public:
		CharacterBuff();
		~CharacterBuff();
		void Initialize();
		void Update();
		void AddBuff(std::shared_ptr<BuffBase> buff);
	private:
		std::vector<std::shared_ptr<BuffBase>> m_buff_list;
		int m_buff_effect[16];
	};
}