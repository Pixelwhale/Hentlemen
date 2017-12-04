//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03～2017.12.04
// 内容　：Windowの基本処理
//-------------------------------------------------------
#include <Core\Application.h>
#include <Def\WindowDef.h>

using namespace Core;

bool Application::InitWindow(HINSTANCE hInstance)
{
	m_hInstance = hInstance;				//インスタンスのハンドル

	m_applicationName = L"RGS_Game";		//WindowClass名前の登録

	WNDCLASS winc;
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = m_hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//ToDo: Change App Icon
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);			//ToDo: Change Cursor Icon
	winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winc.lpszClassName = m_applicationName;
	winc.lpszMenuName = NULL;

	if (!RegisterClass(&winc))
		return false;

	m_hwnd = CreateWindow(
		m_applicationName, WindowDef::WindowName,
		WS_OVERLAPPEDWINDOW,
		0, 0, WindowDef::ScreenWidth, WindowDef::ScreenHeight,
		NULL, NULL, hInstance, NULL);

	if (m_hwnd == NULL)
		return false;

	ShowWindow(m_hwnd, SW_SHOW);
	ShowCursor(true);

	return true;
}

void Application::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	Initialize();
	Load();

	while (!IsEnd())
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		Update();
		Draw();
	}

	Unload();
	ShutDown();
}

void Application::ShutDown()
{
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	UnregisterClass(m_applicationName, m_hInstance);
	m_hInstance = NULL;

	ApplicationHandle = NULL;
}

LRESULT CALLBACK Application::MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

