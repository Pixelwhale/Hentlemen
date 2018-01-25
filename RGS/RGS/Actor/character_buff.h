//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.01.10
// ���e�F�L�����ƃo�t�ɂ�����鏈��
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

		void UpdateTime(BuffFunction& sbattle);
		void UpdateStates(States& sbuff, States& sdebuff);
		void AddBuff(std::shared_ptr<BuffBase> buff);

	private:
		std::vector<std::shared_ptr<BuffBase>> m_buff_list;
	};
}