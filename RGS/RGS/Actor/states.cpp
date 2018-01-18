//-------------------------------------------------------
// ì¬ŽÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#include "states.h"

using namespace Actor;

States::States(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int penp, int penf, int mtk, int mdf, int mpenp, int mpenf, int crit_rate, int crit_mult)
{
	this->lv = lv;
	this->hp_max = hp;
	this->hp_current = hp;
	this->ap_max = ap;
	this->ap_current = ap;
	this->ap_recovery = ap_recovery;
	this->atk = atk;
	this->def = def;
	this->hit = hit;
	this->evd = evd;
	this->penp = penp;
	this->penf = penf;
	this->mtk = mtk;
	this->mdf = mdf;
	this->mpenp = mpenp;
	this->mpenf = mpenf;
	this->crit_rate = crit_rate;
	this->crit_mult = crit_mult;
};

States& States::operator+=(const States& buff)
{
	hp_max += buff.hp_max;
	ap_max += buff.ap_max;
	ap_recovery += buff.ap_recovery;
	atk += buff.atk;
	def += buff.def;
	hit += buff.hit;
	evd += buff.evd;
	penp += buff.penp;
	penf += buff.penf;
	mtk += buff.mtk;
	mdf += buff.mdf;
	mpenp += buff.mpenp;
	mpenf += buff.mpenf;
	crit_rate += buff.crit_rate;
	crit_mult += buff.crit_mult;
	return *this;
}

void States::FullRecovery()
{
	hp_current = hp_max;
	ap_current = ap_max;
}