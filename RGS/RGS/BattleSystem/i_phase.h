//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.18
// ���e�@�F�i�s�i�K��Interface
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

		///<summary>����������</summary>
		virtual void Initialize() = 0;
		///<summary>�X�V����</summary>
		virtual void Update() = 0;
		///<summary>�`�揈��</summary>
		virtual void Draw() = 0;

		///<summary>���̒i�K</summary>
		virtual PhaseEnum NextPhase() = 0;
		///<summary>���̒i�K�͏I����Ă��邩</summary>
		virtual bool IsEnd() = 0;

	protected:
		std::shared_ptr<Device::GameDevice> m_game_device;
	};
}