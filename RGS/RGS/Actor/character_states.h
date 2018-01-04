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
		void Initialize();
		float NextTime();

		int MaxHP();
		int MaxAP();
		int Speed();
		
		//����
		int Atk();
		int Def();
		int Hit();
		int Evd();
		float CritRate();
		float CritMulti();
		float PhyPenP();
		int PhyPenF();

		//���@
		int Mtk();
		int Mdf();
		float MagPenP();
		int MagPenF();

	private:
		int m_lv;	//���x��

		int m_str;	//Strenth�B�U���͂ɉe������
		int m_con;	//Constitution�Bhp�̏���Ɩh��͂ɉe������
		int m_dex;	//Dexterity�B�����U���̓����藦�ɉe������
		int m_agi;	//Agility�B�����U���̉�𗦂ɉe������
		int m_int;	//Intelligence�B���@�U���͂ɉe������
		int m_wis;	//Wisdon�B���@�h��͂ɉe������

		int m_current_hp;
		int m_current_ap;
	};
}