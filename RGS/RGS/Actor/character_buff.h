//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.10
// ���e�F�L�����ƃo�t�ɂ�����鏈��
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