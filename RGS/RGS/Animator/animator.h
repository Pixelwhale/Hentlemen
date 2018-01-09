#pragma once
#include <ssbpLib\SS5Player.h>

namespace Animator 
{
	class AnimationPlayer 
	{
	public:
		AnimationPlayer();
		AnimationPlayer(const AnimationPlayer&);
		~AnimationPlayer();
		void Release();

		void Update(float second = 1.0f / 60.0f);
		void Draw();

	private:
		ss::Player* m_ss_player;
	};
}
