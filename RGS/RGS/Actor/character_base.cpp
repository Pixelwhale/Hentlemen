//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#include <Actor\character_base.h>

using namespace Actor;

CharacterBase::~CharacterBase()
{
	m_buff.~CharacterBuff();
}

void CharacterBase::Initialize()
{
}

void CharacterBase::Update()
{
}