//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#pragma once
#include "buff_function.h"

namespace Actor
{
	struct States : BuffFunction
	{
		States() { Initialize(); };
		States(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int mtk, int mdf, int penp, int penf, int mpenp, int mpenf, int crit_rate, int crit_mult);

		States operator*(const States& buff) const;
		States& operator*=(const States& buff);

		void FullRecovery();

		//set all zero
		void Initialize();

#pragma region BuffFunction
		void Damage(int damage);
		void Heal(int healF, float healP);
#pragma endregion


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
		int mtk;
		int mdf;

		int penp;
		int penf;
		int mpenp;
		int mpenf;
		int crit_rate;
		int crit_mult;
	};
}