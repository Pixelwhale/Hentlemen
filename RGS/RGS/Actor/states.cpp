//-------------------------------------------------------
// ì¬ŽÒFœ@Œ[Ÿ
// ì¬“úF2017.01.15
//-------------------------------------------------------
#include "states.h"

using namespace Actor;

States::States(int lv, int hp, int ap, int ap_recovery, int atk, int def, int hit, int evd, int mtk, int mdf, int penp, int penf, int mpenp, int mpenf, int crit_rate, int crit_mult)
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
	this->mtk = mtk;
	this->mdf = mdf;
	this->penp = penp;
	this->penf = penf;
	this->mpenp = mpenp;
	this->mpenf = mpenf;
	this->crit_rate = crit_rate;
	this->crit_mult = crit_mult;
}

States States::operator*(const States& buff) const
{
	return States(
		lv,
		hp_max * buff.hp_max / 100,
		ap_max * buff.ap_max / 100,
		ap_recovery * buff.ap_recovery / 100,
		atk * buff.atk / 100,
		def * buff.def / 100,
		hit * buff.hit / 100,
		evd * buff.evd / 100,
		mtk * buff.mtk / 100,
		mdf * buff.mdf / 100,
		penp + buff.penp,
		penf + buff.penf,
		mpenp + buff.mpenp,
		mpenf + buff.mpenf,
		crit_rate + buff.crit_rate,
		crit_mult + buff.crit_mult
	);
}

States& States::operator*=(const States& buff)
{
	hp_max *= buff.hp_max;
	ap_max *= buff.ap_max;
	ap_recovery *= buff.ap_recovery;
	atk *= buff.atk;
	def *= buff.def;
	hit *= buff.hit;
	evd *= buff.evd;
	mtk *= buff.mtk;
	mdf *= buff.mdf;
	penp += buff.penp;
	penf += buff.penf;
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

void States::Initialize()
{
	lv = 0;
	hp_max = 0;
	hp_current = 0;
	ap_max = 0;
	ap_current = 0;
	ap_recovery = 0;
	atk = 0;
	def = 0;
	hit = 0;
	evd = 0;
	mtk = 0;
	mdf = 0;
	penp = 0;
	penf = 0;
	mpenp = 0;
	mpenf = 0;
	crit_rate = 0;
	crit_mult = 0;
}

void States::Damage(int damage)
{
	hp_current -= damage;
}

void States::Heal(int healF, float healP)
{
	hp_current += healF;
	hp_current += (int)(hp_max * healP / 100);
}