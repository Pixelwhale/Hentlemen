//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.03�`2017.12.04
// ���e�@�FWindow�̊�{����
//-------------------------------------------------------
#include <Core\Application.h>
#include <Def\WindowDef.h>
#include <DX\DXLib\DxLib.h>

using namespace Core;

Application::Application() 
{
	m_InputState = 0;
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

	m_InputState = std::make_shared<InputState>();
	if (!m_InputState)						//���s������False��Ԃ�
		return false;

	result = m_InputState->Initialize(m_hInstance, m_hwnd);			//Input��������
	if (!result)
		return false;

#pragma endregion

#pragma region Renderer������

	m_Renderer = std::make_shared<Device::Renderer>();
	m_Renderer->Initialize();

#pragma endregion

	return true;
}

void Application::Run()
{
	MSG msg;								//Window�̏�ԃ��b�Z�[�W
	ZeroMemory(&msg, sizeof(MSG));			//msg������

	Initialize();							//Game�̏�����
	Load();									//���[�h�R���e���c

	while (!IsEnd())						//�I�����Ȃ�����GameLoop
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//Window���b�Z�[�W�̊m�F
		{
			if (msg.message == WM_QUIT) break;			//�I��郁�b�Z�[�W����������Loop���甲����
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		if (!m_InputState->Update())		//InputState�X�V
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

	if (m_InputState)									//InputState���V���b�g�_�E������
	{
		m_InputState->ShutDown();
		m_InputState = 0;
	}

	if (m_Renderer)
	{
		m_Renderer->Release();
		m_Renderer = 0;
	}

	DxLib_End();										//DXLib�I������
}

