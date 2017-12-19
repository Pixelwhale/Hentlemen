//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：進行段階のInterface
//-------------------------------------------------------
#pragma once
#include <BattleSystem\phase_enum.h>
#include <Device\game_device.h>

namespace BattleSystem 
{
	class IPhase 
	{
	public:
		IPhase(std::shared_ptr<Device::GameDevice> game_device)
			:m_game_device(game_device)
		{
		}
		~IPhase(){ m_game_device = 0; }

		///<summary>初期化処理</summary>
		virtual void Initialize() = 0;
		///<summary>更新処理</summary>
		virtual void Update() = 0;
		///<summary>描画処理</summary>
		virtual void Draw() = 0;

		///<summary>次の段階</summary>
		virtual PhaseEnum NextPhase() = 0;
		///<summary>この段階は終わっているか</summary>
		virtual bool IsEnd() = 0;

	protected:
		std::shared_ptr<Device::GameDevice> m_game_device;
	};
}