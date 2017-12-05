//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.03�`2017.12.04
// ���e�@�FWindow�̊�{����
//-------------------------------------------------------
#include <Core\Application.h>
#include <Def\WindowDef.h>

using namespace Core;

Application::Application() 
{
	m_InputState = 0;
}

bool Application::InitWindow(HINSTANCE hInstance)
{
	bool result;

	m_hInstance = hInstance;				//�C���X�^���X�̃n���h��

	m_applicationName = L"RGS_Game";		//WindowClass���O�̓o�^

	WNDCLASS winc;							//Window�N���X�\����
	winc.style = CS_HREDRAW | CS_VREDRAW;	//Window�X�^�C��
	winc.lpfnWndProc = WndProc;				//���b�Z�[�W�������\�b�h�w��
	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = m_hInstance;			//Program�C���X�^���X�n���h��
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//ToDo: Change App Icon
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);			//ToDo: Change Cursor Icon
	winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);		//�w�i�F
	winc.lpszClassName = m_applicationName;	//WindowClass�̖��O
	winc.lpszMenuName = NULL;

	if (!RegisterClass(&winc))				//WindowClass�o�^
		return false;						//���s������False��Ԃ�

	m_hwnd = CreateWindow(					//Window���J��
		m_applicationName,					//�g�p����WindowClass
		WindowDef::WindowName,				//Title��
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX),	//Resize�֎~
		0, 0, WindowDef::ScreenWidth, WindowDef::ScreenHeight,		//�ʒu�A�傫��
		NULL, NULL, hInstance, NULL);

	if (m_hwnd == NULL)						//���s������False��Ԃ�
		return false;

	ShowWindow(m_hwnd, SW_SHOW);			//Window��\��
	ShowCursor(true);						//�J�[�\���\��

	m_InputState = std::make_shared<InputState>();			//Input���̂𐶐�
	if (!m_InputState)						//���s������False��Ԃ�
		return false;

	result = m_InputState->Initialize(m_hInstance, m_hwnd);				//Input��������
	if (!result)
		return false;

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
	if(m_InputState)
	{
		m_InputState->ShutDown();
	}

	DestroyWindow(m_hwnd);								//Window��p��
	m_hwnd = NULL;

	UnregisterClass(m_applicationName, m_hInstance);	//�o�^�����N���X������
	m_hInstance = NULL;
}

LRESULT CALLBACK Application::MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, msg, wParam, lParam);	//Default���b�Z�[�W����
}

