//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.19
// 内容　：ローダーのベースシーン
//-------------------------------------------------------
#include <Device\loader.h>

using namespace Device;

Loader::~Loader()
{
	m_resources.clear();
}

void Loader::Initialize()
{
	m_max_num = 0;
	m_counter = 0;
	m_end_flag = false;
	if (m_resources[0] != NULL)
	{
		m_max_num = m_resources.size();
	}
}