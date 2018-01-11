//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのステータスと数値の計算
//-------------------------------------------------------
#include <Actor\character_states.h>

using namespace Actor;

CharacterStates::CharacterStates(int lv, int hp, int ap, int speed, int move, int atk, int def, int hit, int evd, int mtk, int mdf)
{
	m_lv = lv;
	m_base_hp = hp;
	m_base_ap = ap;
	m_base_speed = speed;
	m_base_move = move;
	m_base_atk = atk;
	m_base_def = def;
	m_base_hit = hit;
	m_base_evd = evd;
	m_base_mtk = mtk;
	m_base_mdf = mdf;
	Initialize();
}

void CharacterStates::Initialize()
{
	m_current_hp = MaxHP();
	m_current_ap = MaxAP();
}

float CharacterStates::NextTime()
{
	return (MaxAP() - m_current_ap) / Speed();
}

#pragma region basic parameters;
int CharacterStates::MaxHP()
{
	return m_base_hp;
}
int CharacterStates::MaxAP()
{
	return m_base_ap;
}
int CharacterStates::Speed()
{
	return m_base_speed;
}
int CharacterStates::Move()
{
	return m_base_move;
}
int CharacterStates::Atk()
{
	return m_base_atk;
}
int CharacterStates::Def()
{
	return m_base_def;
}
int CharacterStates::Hit()
{
	return m_base_hit;
}
int CharacterStates::Evd()
{
	return m_base_evd;
}
float CharacterStates::PenP()
{
	return 0;
}
int CharacterStates::PenF()
{
	return 0;
}
int CharacterStates::Mtk()
{
	return m_base_mtk;
}
int CharacterStates::Mdf()
{
	return m_base_mdf;
}
float CharacterStates::MPenP()
{
	return 0;
}
int CharacterStates::MPenF()
{
	return 0;
}
float CharacterStates::CritRate()
{
	return 0.05f;
}
float CharacterStates::CritMult()
{
	return 1.5f;
}
#pragma endregion
