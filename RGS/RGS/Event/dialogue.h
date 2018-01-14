#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace Event
{
	class Dialogue
	{
	public:
		Dialogue();
		~Dialogue();
		void Initialize();
		void Update();
#pragma region Getter ÉÅÉ\ÉbÉh
		std::string GetType();
		void SetTexts(std::vector<std::string> type);
		bool GetIsTyping();
#pragma endregion
		
	private:
		int m_count;
		int m_num;
		int m_span;
		int m_line_count;
		int m_line;
		std::vector<std::string> m_texts;
		std::string m_type;
		bool m_is_typing;
	};
}