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

		// �J�E���g���Z
		_cnt++;

		// �\���������������𒴂��Ă��Ȃ��āA
		// �J�E���g���Ԋu���o������B
		if (_num < _texts.length() && _cnt % _span == _span - 1)
		{
			// ���̕\��������ǉ�
			_type += _texts[_num];
			// �\����������i�߂�
			_num++;
		}
	}
}

#pragma region Getter Setter ���\�b�h

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



