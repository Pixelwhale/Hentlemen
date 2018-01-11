#pragma once
#include <string>
#include <Color\color.h>
#include <ssbpLib\SS5Player.h>

namespace Animator 
{
	class AnimationPlayer 
	{
	public:
		AnimationPlayer();
		AnimationPlayer(const AnimationPlayer& animation_player);
		~AnimationPlayer();

		///<summary>�����ݒ�</summary>
		///<param name="ssbp_file">ssbp_file�̃t�@�C�����i�g���q�����j</param>
		void Initialize(std::string ssbp_file);
		///<summary>�������</summary>
		void Release();
		///<summary>Play����A�j���[�V����</summary>
		///<param name="ssae_file">ssae�̃t�@�C�����i�g���q�����j</param>
		///<param name="animation_name">�A�j���[�V�����̖��O</param>
		///<param name="loop">Loop����񐔁i0�F�����j</param>
		void Play(std::string ssae_file, std::string animation_name, int loop = 0);
		///<summary>�ʒu�ݒ�</summary>
		///<param name="x">x���W</param>
		///<param name="y">y���W</param>
		void SetPosition(float x, float y);
		///<summary>�T�C�Y�ݒ�</summary>
		///<param name="x">x�T�C�Y</param>
		///<param name="y">y�T�C�Y</param>
		void SetScale(float x, float y);
		///<summary>�F�ݒ�</summary>
		///<param name="flip">�F</param>
		void SetColor(Color color);
		///<summary>�����x��ݒ�</summary>
		///<param name="alpha">�����x</param>
		void SetAlpha(int alpha);
		///<summary>�������]</summary>
		///<param name="flip">���]���邩</param>
		void HorizenFlip(bool flip);

		///<summary>�X�V����</summary>
		///<param name="second">�X�V����t���[��</param>
		void Update(float second = 1.0f / 60.0f);
		///<summary>�`�揈��</summary>
		void Draw();

		///<summary>�w�肵�Ă���Loop�񐔂ɒB������</summary>
		bool IsEnd();

	private:
		ss::Player* m_ss_player;		//SpriteStudio��p��Player
		std::string m_current_motion;	//���݃v���C���Ă��郂�[�V����

		bool m_flip;					//���]���邩
		float m_y_scale;				//X�T�C�Y
		float m_x_scale;				//Y�T�C�Y
	};
}
