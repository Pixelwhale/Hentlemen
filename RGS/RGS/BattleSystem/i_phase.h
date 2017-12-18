//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�i�s�i�K��Interface
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