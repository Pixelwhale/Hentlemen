//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Device系をまとめたクラス
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