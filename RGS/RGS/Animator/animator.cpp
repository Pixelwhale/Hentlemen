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
	if (m_ss_player)						//エラー対策
		Release();
}


void AnimationPlayer::Initialize(std::string ssbp_file)
{
	m_ss_player = ss::Player::create();		//実体生成
	m_ss_player->setData(ssbp_file);		//データ設定

	m_flip = false;			//反転設定
	m_y_scale = 1;			//Xサイズ
	m_x_scale = 1;			//Yサイズ

	m_ss_player->setRotation(0.0f, 0.0f, 0.0f);		//回転を設定
	m_ss_player->setFlip(false, false);				//レイアウト自体の反転を設定
}

void AnimationPlayer::Release()
{
	delete(m_ss_player);			//実体を解放
}

void AnimationPlayer::Play(std::string ssae_file, std::string animation_name, int loop)
{
	m_ss_player->play(ssae_file + "/" + animation_name, loop);		//Playするアニメーションを設定
	m_ss_player->clearLoopCount();									//Loopした回数をクリア
}

void AnimationPlayer::SetPosition(float x, float y)
{
	m_ss_player->setPosition(x, y);	//位置設定
}

void AnimationPlayer::SetScale(float x, float y)
{
	if (m_flip && y > 0		||		//反転が必要な場合
		!m_flip && y < 0)			//正常状態
	{
		y = -y;						//反転
	}

	m_y_scale = y;					//大きさを記録
	m_x_scale = x;
	m_ss_player->setScale(x, y);	//大きさを設定
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
	m_flip = flip;						//反転するかを記録

	SetScale(m_x_scale, m_y_scale);		//大きさと向きを設定
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

	if (loop == 0)									//無限Loopの場合は終了しない
		return false;

	return m_ss_player->getLoopCount() >= loop;		//指定の回数に超えた場合
}
