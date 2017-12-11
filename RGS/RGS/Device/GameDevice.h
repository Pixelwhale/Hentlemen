//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Device系をまとめたクラス
//-------------------------------------------------------
#pragma once
#include <memory>
#include <Core\InputState.h>
#include <Device\Renderer.h>
#include <Device\Projector.h>
#include <Device\ContentManager.h>
#include <Device\Random.h>

namespace Device
{
	class GameDevice
	{
	public:
		GameDevice(
			std::shared_ptr<Core::InputState>	input,
			std::shared_ptr<Renderer>			renderer,
			std::shared_ptr<ContentManager>		content);
		GameDevice(const GameDevice&);
		~GameDevice();

		///<summary>入力装置</summary>
		std::shared_ptr<Core::InputState>	GetInput();
		///<summary>レンダラー</summary>
		std::shared_ptr<Renderer>			GetRenderer();
		///<summary>カメラ</summary>
		std::shared_ptr<Projector>			GetProjector();
		///<summary>コンテントマネージャー</summary>
		std::shared_ptr<ContentManager>		GetContent();
		///<summary>ランダム</summary>
		Random*								GetRandom();

	private:
		std::shared_ptr<Core::InputState>	m_input;			//入力装置
		std::shared_ptr<Renderer>			m_renderer;			//レンダラー
		std::shared_ptr<Projector>			m_projector;		//カメラ
		std::shared_ptr<ContentManager>		m_content;			//コンテンツ
		Random								m_rand;				//ランダム
	};
}