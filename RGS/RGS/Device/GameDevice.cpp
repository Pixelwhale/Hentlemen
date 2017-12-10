//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FDevice�n���܂Ƃ߂��N���X
//-------------------------------------------------------
#include <Device\GameDevice.h>

using namespace Device;

GameDevice::GameDevice(
	std::shared_ptr<Core::InputState>	input,
	std::shared_ptr<Renderer>			renderer,
	std::shared_ptr<ContentManager>		content)
	:m_input(input), m_renderer(renderer), m_content(content)
{
}

GameDevice::GameDevice(const GameDevice&)
{
}

GameDevice::~GameDevice()
{
	m_input = 0;
	m_renderer = 0;
	m_content = 0;
}

std::shared_ptr<Core::InputState>	GameDevice::GetInput()
{
	return m_input;
}

std::shared_ptr<Renderer>			GameDevice::GetRenderer()
{
	return m_renderer;
}

std::shared_ptr<ContentManager>		GameDevice::GetContent()
{
	return m_content;
}