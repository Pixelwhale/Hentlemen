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
		CharacterStates(int lv, int str, int con, int dex, int agi, int inte, int wis);
		///<summary>��{�X�e�[�^�X�ƃX�L���őS���̃X�e�[�^�X���v�Z����</summary>
		void Initialize();
		float NextTime();

	private:
		int m_lv;	//���x��

		int m_str;	//Strenth�B�U���͂ɉe������
		int m_con;	//Constitution�Bhp�̏���Ɩh��͂ɉe������
		int m_dex;	//Dexterity�B�����U���̓����藦�ɉe������
		int m_agi;	//Agility�B�����U���̉�𗦂ɉe������
		int m_int;	//Intelligence�B���@�U���͂ɉe������
		int m_wis;	//Wisdon�B���@�h��͂ɉe������

		//default = a0(base) * a1 + a2
		int m_hp[3];			//Health Point�B0�ɂȂ����玀��
		int m_ap[3];			//Action Point�B�s������Ƃ�������ʂł��B�s�����Ƃɂ�����ʂ͈Ⴂ�B
		int m_current_hp;
		int m_current_ap;

		int m_speed[3];			//ap�̉񕜑��x�ɉe������B

		//����
		float m_atk[3];
		float m_def[3];
		float m_accuracy[3];
		float m_evasion[3];
		float m_crit_rate[2];	//ao(base) + a1
		float m_crit_multi[2];	//a0(base) + a1
		float m_phy_pen[2];		//a0% + a1	����̕����h��͂𖳎�����

		//���@
		float m_mtk[3];
		float m_mdf[3];
		float m_mag_pen[2];		//a0% + a1	����̖��@�h��͂𖳎�����
	};
}