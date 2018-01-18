//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once

namespace Actor
{


	struct States
	{
		//set all zero
		States();
		States(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int penp, int penf, int mtk, int mdf, int mpenp, int mpenf, int crit_rate, int crit_mult);

		States operator+(const States& buff) const;
		States& operator+=(const States& buff);

		void FullRecovery();
		void Initialize();

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