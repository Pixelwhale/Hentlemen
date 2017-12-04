//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
//-------------------------------------------------------
#pragma once
#include <Core\Application.h>

namespace Core
{
	class Game : public Application
	{
	public:
		Game() {}						//�R���X�g���N�^
		~Game() {}						//�f�X�g���N�^�[

	protected:
		virtual void Initialize();		//������
		virtual void Load();			//���\�[�X�ǂݍ���
		virtual void Unload();			//���\�[�X���
		virtual void Update();			//�Q�[���X�V
		virtual void Draw();			//�`��
		virtual bool IsEnd();			//�I���m�F���郁�\�b�h

	private:
		bool m_endFlag;					//�Q�[���I���̃t���O
	};
}