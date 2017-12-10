//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FDevice�n���܂Ƃ߂��N���X
//-------------------------------------------------------
#pragma once
#include <memory>
#include <Core\InputState.h>
#include <Device\Renderer.h>
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

		std::shared_ptr<Core::InputState>	GetInput();
		std::shared_ptr<Renderer>			GetRenderer();
		std::shared_ptr<ContentManager>		GetContent();
		Random*								GetRandom();

	private:
		std::shared_ptr<Core::InputState>	m_input;
		std::shared_ptr<Renderer>			m_renderer;
		std::shared_ptr<ContentManager>		m_content;
		Random								m_rand;
	};
}