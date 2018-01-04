//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.13
// 内容　：キャラクターのステータスと数値の計算
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class CharacterStates
	{
	public:
		CharacterStates(int lv, int str, int con, int dex, int agi, int inte, int wis);
		void Initialize();
		float NextTime();

		int MaxHP();
		int MaxAP();
		int Speed();
		
		//物理
		int Atk();
		int Def();
		int Hit();
		int Evd();
		float CritRate();
		float CritMulti();
		float PhyPenP();
		int PhyPenF();

		//魔法
		int Mtk();
		int Mdf();
		float MagPenP();
		int MagPenF();

	private:
		int m_lv;	//レベル

		int m_str;	//Strenth。攻撃力に影響する
		int m_con;	//Constitution。hpの上限と防御力に影響する
		int m_dex;	//Dexterity。物理攻撃の当たり率に影響する
		int m_agi;	//Agility。物理攻撃の回避率に影響する
		int m_int;	//Intelligence。魔法攻撃力に影響する
		int m_wis;	//Wisdon。魔法防御力に影響する

		int m_current_hp;
		int m_current_ap;
	};
}