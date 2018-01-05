#include "dialogue.h"

using namespace Device;

Dialogue::Dialogue()
{
}

Dialogue::~Dialogue() 
{
}

void Dialogue::Initialize()
{
	_cnt = 0;
	_num = 0;
	_span = 15;
	_lineCnt = 0;
	_line = 0;
	_isTyping = false;
	_type = "";
	_texts = "";
}

void Dialogue::Update()
{
	if (_texts.length() > 0)
	{
		_isTyping = true;

		// カウント加算
		_cnt++;

		// 表示文字数が長さを超えていなくて、
		// カウントが間隔分経ったら。
		if (_num < _texts.length() && _cnt % _span == _span - 1)
		{
			// 次の表示文字を追加
			_type += _texts[_num];
			// 表示文字数を進める
			_num++;
		}
	}
}

#pragma region Getter Setter メソッド

std::string Dialogue::GetType()
{
	return _type;
}

bool Dialogue::GetIsTyping()
{
	return _isTyping;
}

void Dialogue::SetTexts(std::string texts)
{
	_texts = texts;
}

#pragma endregion



