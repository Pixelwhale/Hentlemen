//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.03�`2017.12.04
// ���e�@�FWindow�̊�{����
//-------------------------------------------------------
#include <Core\application.h>
#include <Def\window_def.h>
#include <DX\DXLib\DxLib.h>

using namespace Core;

Application::Application() 
{
	m_inputState = 0;
	m_contentManager = 0;
	m_renderer = 0;
}

bool Application::InitWindow()
{
	bool result;

#pragma region DxLib������
	SetOutApplicationLogValidFlag(false);			//Log�������o�����Ȃ�
	SetWindowText(WindowDef::WindowName);			//Title�ݒ�
	SetGraphMode(
		WindowDef::ScreenWidth,						//WindowSize
		WindowDef::ScreenHeight,
		32, 60);									//Color 32bit  60Frame
	ChangeWindowMode(WindowDef::IsWindow);			//�S��ʐݒ�
	DxLib_Init();									//DXLibrary������
	SetMouseDispFlag(false);						//Mouse�\�����Ȃ�

	m_hwnd = DxLib::GetMainWindowHandle();			//WindowHandle���擾
	m_hInstance = DxLib::GetTaskInstance();			//Program�̎��̂��擾

#pragma endregion

#pragma region InputState������

	m_inputState = std::make_shared<InputState>();
	if (!m_inputState)						//���s������False��Ԃ�
		return false;

	result = m_inputState->Initialize(m_hInstance, m_hwnd);			//Input��������
	if (!result)
		return false;

#pragma endregion

#pragma region ContentManager������
	m_contentManager = std::make_shared<Device::ContentManager>();
	m_contentManager->Initialize();
#pragma endregion

#pragma region Renderer������

	m_renderer = std::make_shared<Device::Renderer>(m_contentManager);
	m_renderer->Initialize();

#pragma endregion

	return true;
}

void Application::Run()
{
	MSG msg;								//Window�̏�ԃ��b�Z�[�W
	ZeroMemory(&msg, sizeof(MSG));			//msg������

	Initialize();							//Game�̏�����
	Load();									//���[�h�R���e���c

	while (ProcessMessage()== 0 && !IsEnd())						//�I�����Ȃ�����GameLoop
	{
		if (!m_inputState->Update())		//InputState�X�V
			break;

		Update();							//Game�̃A�b�v�f�[�g
		Draw();								//Game�̕`�揈��
	}

	Unload();								//�R���e���c�������
	ShutDown();								//Window�̃V���b�g�_�E������
}

void Application::ShutDown()
{
	SetMouseDispFlag(true);								//Mouse�\��

	if (m_inputState)									//InputState���V���b�g�_�E������
	{
		m_inputState->ShutDown();
		m_inputState = 0;
	}

	if (m_renderer)										//Renderer���V���b�g�_�E������
	{
		m_renderer->Release();
		m_renderer = 0;
	}

	if (m_contentManager) 								//Content���V���b�g�_�E������
	{
		m_contentManager->Release();
		m_contentManager = 0;
	}

	DxLib_End();										//DXLib�I������
}

