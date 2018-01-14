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
	// カウント加算
	m_count++;

	if (m_line_count > 0)
	{
		// 改行待ち時間カウント
		m_line_count++;

		if (m_line_count > m_span * 4)
		{
			// 改行する
			m_type += "\n";
			// 表示している行数を増やす
			m_line++;
			// 表示位置を0に
			m_num = 0;
			// カウント初期化
			m_line_count = 0;
			m_count = 0;
		}
	}
		// 表示文字数が長さを超えていなくて、
		// カウントが間隔分経ったら。
		if (m_num < m_texts.at(m_line).length()
			&& m_count % m_span == m_span - 1)
		{
			// 次の表示文字を追加
			m_type += m_texts.at(m_line).at(m_num);
			// 表示文字数を進める
			m_num++;

			// 1行分最後まで表示して、
			// 次の行がまだあれば
			if (m_num >= m_texts.at(m_line).length() &&
				m_line < m_texts.size() - 1)
			{
				// 改行待ち時間を1にする
				m_line_count++;
			}
		}
}

#pragma region Getter Setter メソッド

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



