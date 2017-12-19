//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.19
// 内容　：ローダーのベースシーン
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
		int m_max_num;		//コンテンツの数
		int m_counter;		//while(counter<max){ ローディング処理 }
		bool m_end_flag;
	};
}