//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FDevice�n���܂Ƃ߂��N���X
//-------------------------------------------------------
#pragma once
#include <memory>
#include <Core\input_state.h>
#include <Device\renderer.h>
#include <Device\projector.h>
#include <Device\content_manager.h>
#include <Device\random.h>

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

		///<summary>���͑��u</summary>
		std::shared_ptr<Core::InputState>	GetInput();
		///<summary>�����_���[</summary>
		std::shared_ptr<Renderer>			GetRenderer();
		///<summary>�J����</summary>
		std::shared_ptr<Projector>			GetProjector();
		///<summary>�R���e���g�}�l�[�W���[</summary>
		std::shared_ptr<ContentManager>		GetContent();
		///<summary>�����_��</summary>
		Random*								GetRandom();

	private:
		std::shared_ptr<Core::InputState>	m_input;			//���͑��u
		std::shared_ptr<Renderer>			m_renderer;			//�����_���[
		std::shared_ptr<Projector>			m_projector;		//�J����
		std::shared_ptr<ContentManager>		m_content;			//�R���e���c
		Random								m_rand;				//�����_��
	};
}