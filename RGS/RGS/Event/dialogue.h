#pragma once
#include <string>
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
#pragma region Getter ƒƒ\ƒbƒh
		std::string GetType();
		void SetTexts(std::string type);
		bool GetIsTyping();
#pragma endregion
		
	private:
		int _cnt;
		int _num;
		int _span;
		int _lineCnt;
		int _line;
		std::string _texts;
		std::string _type;
		bool _isTyping;
	};
}