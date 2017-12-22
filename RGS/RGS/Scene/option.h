//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：オプションのシーン。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Option : public SceneBase
	{
	public:
		Option();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}