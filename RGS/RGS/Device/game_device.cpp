//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FDevice�n���܂Ƃ߂��N���X
//-------------------------------------------------------
#include <Device\game_device.h>

using namespace Device;

GameDevice::GameDevice()
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
	m_projector = 0;
}

bool GameDevice::Initialize(HINSTANCE h_instance, HWND hwnd)
{
	//Input������
	bool result;
	m_input = std::make_shared<Core::InputState>();
	result = m_input->Initialize(h_instance, hwnd);
	if (!result)
		return false;
	//Content������
	m_content = std::make_shared<Device::ContentManager>();
	m_content->Initialize();
	//Renderer������
	m_renderer = std::make_shared<Device::Renderer>(m_content);
	m_renderer->Initialize();
	//Random������
	m_rand = Random();
	//Projector������
	m_projector = std::make_shared<Projector>();
	m_projector->Initialize();

	return true;
}

void GameDevice::ShutDown() 
{
	if (m_input)					//Input�̉������
	{
		m_input->ShutDown();
		m_input = 0;
	}

	if (m_renderer)					//Renderer�̉������
	{
		m_renderer->Release();
		m_renderer = 0;
	}

	m_projector = 0;

	if (m_content)					//Content�̉������
	{
		m_content->Release();
		m_content = 0;
	}
}

std::shared_ptr<Core::InputState> GameDevice::GetInput()
{
	return m_input;
}

std::shared_ptr<Renderer> GameDevice::GetRenderer()
{
	return m_renderer;
}

std::shared_ptr<Projector> GameDevice::GetProjector() 
{
	return m_projector;
}

std::shared_ptr<ContentManager> GameDevice::GetContent()
{
	return m_content;
}

Random* GameDevice::GetRandom() 
{
	return &m_rand;
}