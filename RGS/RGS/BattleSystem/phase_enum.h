//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�i�s���̒i�K
//-------------------------------------------------------
#pragma once

namespace BattleSystem 
{
	enum PhaseEnum
	{
		kWait,				//���Ԃ�҂�
		kMoveRange,			//�ړ��͈͂��v�Z
		kPlayerControl,		//�v���C���[����
		kAIControl,			//AI�s��
		kCaculate,			//Buff,Damage�v�Z
		kAnimation,			//�A�j���[�V�������o
		kCheckEnd,			//���s�������m�F
		kEvent,				//�C�x���g�̏I����҂�
	};
}