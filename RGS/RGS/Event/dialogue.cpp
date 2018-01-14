#include "dialogue.h"

using namespace Event;

Dialogue::Dialogue()
{
}

Dialogue::~Dialogue() 
{
}

void Dialogue::Initialize()
{
	m_count = 0;
	m_num = 0;
	m_span = 15;
	m_line_count = 0;
	m_line = 0;
	m_is_typing = false;
	m_type = "";
	
}

void Dialogue::Update()
{
	// �J�E���g���Z
	m_count++;

	if (m_line_count > 0)
	{
		// ���s�҂����ԃJ�E���g
		m_line_count++;

		if (m_line_count > m_span * 4)
		{
			// ���s����
			m_type += "\n";
			// �\�����Ă���s���𑝂₷
			m_line++;
			// �\���ʒu��0��
			m_num = 0;
			// �J�E���g������
			m_line_count = 0;
			m_count = 0;
		}
	}
		// �\���������������𒴂��Ă��Ȃ��āA
		// �J�E���g���Ԋu���o������B
		if (m_num < m_texts.at(m_line).length()
			&& m_count % m_span == m_span - 1)
		{
			// ���̕\��������ǉ�
			m_type += m_texts.at(m_line).at(m_num);
			// �\����������i�߂�
			m_num++;

			// 1�s���Ō�܂ŕ\�����āA
			// ���̍s���܂������
			if (m_num >= m_texts.at(m_line).length() &&
				m_line < m_texts.size() - 1)
			{
				// ���s�҂����Ԃ�1�ɂ���
				m_line_count++;
			}
		}
}

#pragma region Getter Setter ���\�b�h

std::string Dialogue::GetType()
{
	return m_type;
}

bool Dialogue::GetIsTyping()
{
	return m_is_typing;
}

void Dialogue::SetTexts(std::vector<std::string> texts)
{
	m_texts = texts;
}

#pragma endregion



