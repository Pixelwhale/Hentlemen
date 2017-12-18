//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.18
// 内容　：進行段階のInterface
//-------------------------------------------------------
#pragma once
#include <BattleSystem\phase_enum.h>

namespace BattleSystem 
{
	class IPhase 
	{
	public:
		~IPhase() {}

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual PhaseEnum NextPhase() = 0;
		virtual bool IsEnd() = 0;
	};
}