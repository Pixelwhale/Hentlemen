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

		///<summary>初期設定</summary>
		///<param name="ssbp_file">ssbp_fileのファイル名（拡張子抜き）</param>
		void Initialize(std::string ssbp_file);
		///<summary>解放処理</summary>
		void Release();
		///<summary>Playするアニメーション</summary>
		///<param name="ssae_file">ssaeのファイル名（拡張子抜き）</param>
		///<param name="animation_name">アニメーションの名前</param>
		///<param name="loop">Loopする回数（0：無限）</param>
		void Play(std::string ssae_file, std::string animation_name, int loop = 0);
		///<summary>位置設定</summary>
		///<param name="x">x座標</param>
		///<param name="y">y座標</param>
		void SetPosition(float x, float y);
		///<summary>サイズ設定</summary>
		///<param name="x">xサイズ</param>
		///<param name="y">yサイズ</param>
		void SetScale(float x, float y);
		///<summary>色設定</summary>
		///<param name="flip">色</param>
		void SetColor(Color color);
		///<summary>透明度を設定</summary>
		///<param name="alpha">透明度</param>
		void SetAlpha(int alpha);
		///<summary>水平反転</summary>
		///<param name="flip">反転するか</param>
		void HorizenFlip(bool flip);

		///<summary>更新処理</summary>
		///<param name="second">更新するフレーム</param>
		void Update(float second = 1.0f / 60.0f);
		///<summary>描画処理</summary>
		void Draw();

		///<summary>指定しているLoop回数に達したか</summary>
		bool IsEnd();

	private:
		ss::Player* m_ss_player;		//SpriteStudio専用のPlayer
		std::string m_current_motion;	//現在プレイしているモーション

		bool m_flip;					//反転するか
		float m_y_scale;				//Xサイズ
		float m_x_scale;				//Yサイズ
	};
}
