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
		kStartTurn,			//�J�n���̏����A�ړ��͈͂̌v�Z�Ȃ�
		kPlayerControl,		//�v���C���[����
		kAIControl,			//AI�s��
		kCaculate,			//Buff,Damage�v�Z
		kAnimation,			//�A�j���[�V�������o
		kCheckEnd,			//���s�������m�F
		kEndTurn,			//����I�����̏����iBuff�ADebuff�̃^�[�������A�^�[���̒ǉ��Ȃǁj
		kEvent,				//�C�x���g�̏I����҂�
		kWin,				//����
		kLose,				//�s�k
	};
}