//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once

namespace Actor
{
	struct States
	{
		States() {};
		States(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int penp, int penf, int mtk, int mdf, int mpenp, int mpenf, int crit_rate, int crit_mult);

		friend const States operator+(const States& basis, const States& buff)
		{
			return States(
				basis.lv,
				basis.hp_max + buff.hp_max,
				basis.ap_max + buff.ap_max,
				basis.ap_recovery + buff.ap_recovery,
				basis.atk + buff.atk,
				basis.def + buff.def,
				basis.hit + buff.hit,
				basis.evd + buff.evd,
				basis.penp + buff.penp,
				basis.penf + buff.penf,
				basis.mtk + buff.mtk,
				basis.mdf + buff.mdf,
				basis.mpenp + buff.mpenp,
				basis.mpenf + buff.mpenf,
				basis.crit_rate + buff.crit_rate,
				basis.crit_mult + buff.crit_mult
			);
		};
		States& operator+=(const States& buff);

		void FullRecovery();



		int lv;	//ƒŒƒxƒ‹

		int hp_max;
		int hp_current;
		int ap_max;
		int ap_current;
		int ap_recovery;

		int atk;
		int def;
		int hit;
		int evd;
		int penp;
		int penf;

		int mtk;
		int mdf;
		int mpenp;
		int mpenf;

		int crit_rate;
		int crit_mult;
	};
}