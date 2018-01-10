//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.13
// ���e�@�F�L�����N�^�[�̃X�e�[�^�X�Ɛ��l�̌v�Z
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

		//���
		int MaxHP();
		int MaxAP();
		int Speed();
		
		//����
		int Atk();
		int Def();
		int Hit();
		int Evd();
		float PenP();
		int PenF();

		//���@
		int Mtk();
		int Mdf();
		float MPenP();
		int MPenF();

		//����
		float CritRate();
		float CritMult();

	private:
		int m_lv;	//���x��

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