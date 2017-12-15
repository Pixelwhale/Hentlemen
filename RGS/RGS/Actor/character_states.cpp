//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのステータスと数値の計算
//-------------------------------------------------------
#include <Actor\character_states.h>

using namespace Actor;

CharacterStates::CharacterStates(int lv, int str, int con, int dex, int agi, int inte, int wis)
{
	this->m_lv = lv;
	this->m_str = str;
	this->m_con = con;
	this->m_dex = dex;
	this->m_agi = agi;
	this->m_int = inte;
	this->m_wis = wis;
	Initialize();
}

void CharacterStates::Initialize()
{
	//テスト用
	m_hp[0] = 100 + m_lv * 10 + m_con * 5;
	m_ap[0] = 500;
	m_speed[0] = 100;
	
	m_atk[0] = 20 + m_lv * 1 + m_str * 4;
	m_def[0] = 20 + m_lv * 1 + m_con * 4;
	m_accuracy[0] = 50 + m_lv * 2 + m_dex * 8;
	m_evasion[0] = 50 + m_lv * 1 + m_agi * 6;
	m_crit_rate[0] = 5;
	m_crit_multi[0] = 150;
	m_phy_pen[0] = 0;
	m_phy_pen[1] = 0;

	m_mtk[0] = 0 + m_int * 5;
	m_mdf[0] = 0 + m_wis * 5;
	m_mag_pen[0] = 0;
	m_mag_pen[1] = 0;
}