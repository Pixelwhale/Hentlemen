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
		///<summary>基本ステータスとスキルで全部のステータスを計算する</summary>
		void Initialize();
		float NextTime();

	private:
		int m_lv;	//レベル

		int m_str;	//Strenth。攻撃力に影響する
		int m_con;	//Constitution。hpの上限と防御力に影響する
		int m_dex;	//Dexterity。物理攻撃の当たり率に影響する
		int m_agi;	//Agility。物理攻撃の回避率に影響する
		int m_int;	//Intelligence。魔法攻撃力に影響する
		int m_wis;	//Wisdon。魔法防御力に影響する

		//default = a0(base) * a1 + a2
		int m_hp[3];			//Health Point。0になったら死んだ
		int m_ap[3];			//Action Point。行動するときかかる量です。行動ことにかかる量は違い。
		int m_current_hp;
		int m_current_ap;

		int m_speed[3];			//apの回復速度に影響する。

		//物理
		float m_atk[3];
		float m_def[3];
		float m_accuracy[3];
		float m_evasion[3];
		float m_crit_rate[2];	//ao(base) + a1
		float m_crit_multi[2];	//a0(base) + a1
		float m_phy_pen[2];		//a0% + a1	相手の物理防御力を無視する

		//魔法
		float m_mtk[3];
		float m_mdf[3];
		float m_mag_pen[2];		//a0% + a1	相手の魔法防御力を無視する
	};
}