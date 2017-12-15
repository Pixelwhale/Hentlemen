//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのステータスと数値の計算
//-------------------------------------------------------
#include <Actor\character_states.h>

using namespace Actor;

CharacterStates::CharacterStates(int lv, int str, int con, int dex, int agi, int inte, int wis)
{
	m_lv = lv;
	m_str = str;
	m_con = con;
	m_dex = dex;
	m_agi = agi;
	m_int = inte;
	m_wis = wis;
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
	return 100 + m_lv * 10 + m_con * 5;
}
int CharacterStates::MaxAP()
{
	return 500;
}
int CharacterStates::Speed()
{
	return 100;
}
int CharacterStates::Atk()
{
	return 20 + m_lv * 1 + m_str * 4;
}
int CharacterStates::Def()
{
	return 20 + m_lv * 1 + m_con * 4;
}
int CharacterStates::Hit()
{
	return 20 + m_lv * 1 + m_dex * 4;
}
int CharacterStates::Evd()
{
	return 50 + m_lv * 1 + m_agi * 6;
}
float CharacterStates::CritRate()
{
	return 0.05f;
}
float CharacterStates::CritMulti() {
	return 1.5f;
}
float CharacterStates::PhyPenP()
{
	return 0;
}
int CharacterStates::PhyPenF()
{
	return 0;
}
int CharacterStates::Mtk()
{
	return 0 + m_int * 5;
}
int CharacterStates::Mdf()
{
	return 0 + m_wis * 5;
}
float CharacterStates::MagPenP()
{
	return 0;
}
int CharacterStates::MagPenF()
{
	return 0;
}
#pragma endregion
