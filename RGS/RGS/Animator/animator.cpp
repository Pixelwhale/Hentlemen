#include <Animator\animator.h>

using namespace Animator;

AnimationPlayer::AnimationPlayer()
{
}

AnimationPlayer::AnimationPlayer(const AnimationPlayer& animation_player) 
{
}

AnimationPlayer::~AnimationPlayer()
{
	if (m_ss_player)						//�G���[�΍�
		Release();
}


void AnimationPlayer::Initialize(std::string ssbp_file)
{
	m_ss_player = ss::Player::create();		//���̐���
	m_ss_player->setData(ssbp_file);		//�f�[�^�ݒ�

	m_flip = false;			//���]�ݒ�
	m_y_scale = 1;			//X�T�C�Y
	m_x_scale = 1;			//Y�T�C�Y

	m_ss_player->setRotation(0.0f, 0.0f, 0.0f);		//��]��ݒ�
	m_ss_player->setFlip(false, false);				//���C�A�E�g���̂̔��]��ݒ�
}

void AnimationPlayer::Release()
{
	delete(m_ss_player);			//���̂����
}

void AnimationPlayer::Play(std::string ssae_file, std::string animation_name, int loop)
{
	m_ss_player->play(ssae_file + "/" + animation_name, loop);		//Play����A�j���[�V������ݒ�
	m_ss_player->clearLoopCount();									//Loop�����񐔂��N���A
}

void AnimationPlayer::SetPosition(float x, float y)
{
	m_ss_player->setPosition(x, y);	//�ʒu�ݒ�
}

void AnimationPlayer::SetScale(float x, float y)
{
	if (m_flip && y > 0		||		//���]���K�v�ȏꍇ
		!m_flip && y < 0)			//������
	{
		y = -y;						//���]
	}

	m_y_scale = y;					//�傫�����L�^
	m_x_scale = x;
	m_ss_player->setScale(x, y);	//�傫����ݒ�
}

void AnimationPlayer::SetColor(Color color)
{
	m_ss_player->setColor(color.r, color.g, color.b);
}

void AnimationPlayer::SetAlpha(int alpha)
{
	m_ss_player->setAlpha(alpha);
}

void AnimationPlayer::HorizenFlip(bool flip)
{
	m_flip = flip;						//���]���邩���L�^

	SetScale(m_x_scale, m_y_scale);		//�傫���ƌ�����ݒ�
}

void AnimationPlayer::Update(float second)
{
	m_ss_player->update(second);
}

void AnimationPlayer::Draw()
{
	m_ss_player->draw();
}

bool Animator::AnimationPlayer::IsEnd()
{
	int loop = m_ss_player->getLoop();

	if (loop == 0)									//����Loop�̏ꍇ�͏I�����Ȃ�
		return false;

	return m_ss_player->getLoopCount() >= loop;		//�w��̉񐔂ɒ������ꍇ
}
