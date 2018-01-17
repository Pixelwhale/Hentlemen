//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once

namespace Actor
{
	struct States
	{
		void Initialize(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int penp, int penf, int mtk, int mdf, int mpenp, int mpenf, int crit_rate, int crit_mult)
		{
			m_lv = lv;
			m_hp_max = hp;
			m_hp_current = hp;
			m_ap_max = ap;
			m_ap_current = ap;
			m_ap_recovery = ap_recovery;
			m_atk = atk;
			m_def = def;
			m_hit = hit;
			m_evd = evd;
			m_penp = penp;
			m_penf = penf;
			m_mtk = mtk;
			m_mdf = mdf;
			m_mpenp = mpenp;
			m_mpenf = mpenf;
			m_crit_rate = crit_rate;
			m_crit_mult = crit_mult;
		}

		int m_lv;	//ƒŒƒxƒ‹

		int m_hp_max;
		int m_hp_current;
		int m_ap_max;
		int m_ap_current;
		int m_ap_recovery;

		int m_atk;
		int m_def;
		int m_hit;
		int m_evd;
		int m_penp;
		int m_penf;

		int m_mtk;
		int m_mdf;
		int m_mpenp;
		int m_mpenf;

		int m_crit_rate;
		int m_crit_mult;
	};
}