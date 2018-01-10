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
		CharacterStates(int lv, int hp, int ap, int speed, int atk, int def, int hit, int evd, int mtk, int mdf);
		void Initialize();
		float NextTime();

		//一般
		int MaxHP();
		int MaxAP();
		int Speed();
		
		//物理
		int Atk();
		int Def();
		int Hit();
		int Evd();
		float PenP();
		int PenF();

		//魔法
		int Mtk();
		int Mdf();
		float MPenP();
		int MPenF();

		//両方
		float CritRate();
		float CritMult();

	private:
		int m_lv;	//レベル

		int m_base_hp;
		int m_base_ap;
		int m_base_speed;

		int m_base_atk;
		int m_base_def;
		int m_base_hit;
		int m_base_evd;
		int m_base_mtk;
		int m_base_mdf;

		int m_current_hp;
		int m_current_ap;
	};
}