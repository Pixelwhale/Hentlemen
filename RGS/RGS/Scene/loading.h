//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.19
// 内容　：テクスチャ、音などをロードするシーン
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Scene\scene_base.h>

namespace Scene
{
	class Loading : SceneBase
	{
	public:
		Loading(Device::GameDevice& game_device) : m_game_device(game_device), SceneBase(game_device) {};
		void LoadContents();
		void UnloadContents();
		void Update();
		void Draw();
	private:
		Device::GameDevice& m_game_device;
	};
}