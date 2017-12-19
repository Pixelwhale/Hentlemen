//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.19
// ���e�@�F���[�_�[�̃x�[�X�V�[��
//-------------------------------------------------------
#pragma once
#include <vector>

namespace Device
{
	class Loader
	{
	public:
		Loader(std::vector<std::string[2]>& resources) : m_resources(resources) {};
		~Loader();
		void Initialize();
		int Count() { return m_max_num; };
		int CurrentCount() { return m_counter; };
		bool IsEnd() { return m_end_flag; };
		virtual void Update() = 0;
	protected:
		std::vector<std::string[2]>& m_resources;
		int m_max_num;		//�R���e���c�̐�
		int m_counter;		//while(counter<max){ ���[�f�B���O���� }
		bool m_end_flag;
	};
}