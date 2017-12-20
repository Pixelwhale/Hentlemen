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
	m_input_state = 0;
	m_game_device = 0;
}

bool Application::InitWindow()
{
	bool result;

#pragma region DxLib������
	SetUseDirect3DVersion(DX_DIRECT3D_9EX);
	SetOutApplicationLogValidFlag(false);			//Log�������o�����Ȃ�
	SetWindowText(WindowDef::kWindowName);			//Title�ݒ�
	SetGraphMode(
		WindowDef::kScreenWidth,						//WindowSize
		WindowDef::kScreenHeight,
		32, 60);									//Color 32bit  60Frame
	ChangeWindowMode(WindowDef::kIsWindow);			//�S��ʐݒ�
	DxLib_Init();									//DXLibrary������
	SetMouseDispFlag(false);						//Mouse�\�����Ȃ�

	m_hwnd = DxLib::GetMainWindowHandle();			//WindowHandle���擾
	m_hInstance = DxLib::GetTaskInstance();			//Program�̎��̂��擾

#pragma endregion

#pragma region GameDevice������

	m_game_device = Device::GameDevice::GetInstance();
	result = m_game_device->Initialize(m_hInstance, m_hwnd);
	if (!result)
		return false;

#pragma endregion

	m_input_state = m_game_device->GetInput();

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
		if (!m_input_state->Update())		//InputState�X�V
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

	if (m_game_device)									//Game Device���V���b�g�_�E������
	{
		m_game_device->ShutDown();
	}

	delete m_game_device;

	DxLib_End();										//DXLib�I������
}

