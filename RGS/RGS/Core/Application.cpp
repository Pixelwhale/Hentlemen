//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03～2017.12.04
// 内容　：Windowの基本処理
//-------------------------------------------------------
#include <Core\Application.h>
#include <Def\WindowDef.h>

using namespace Core;

Application::Application() 
{
	m_InputState = 0;
	m_GraphicDevice = 0;
}

bool Application::InitWindow(HINSTANCE hInstance)
{
	bool result;

	m_hInstance = hInstance;				//インスタンスのハンドル

#pragma region Window設定

	m_applicationName = L"RGS_Game";		//WindowClass名前の登録

	WNDCLASS winc;							//Windowクラス構造体
	winc.style = CS_HREDRAW | CS_VREDRAW;	//Windowスタイル
	winc.lpfnWndProc = WndProc;				//メッセージ処理メソッド指定
	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = m_hInstance;			//Programインスタンスハンドル
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//ToDo: Change App Icon
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);						//ToDo: Change Cursor Icon
	winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);		//背景色
	winc.lpszClassName = m_applicationName;							//WindowClassの名前
	winc.lpszMenuName = NULL;

	if (!RegisterClass(&winc))				//WindowClass登録
		return false;						//失敗したらFalseを返す

	if (WindowDef::FullScreen)				//全画面の場合
	{
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)WindowDef::ScreenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)WindowDef::ScreenHeight;
		dmScreenSettings.dmBitsPerPel = 32;							//32Bit
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);	//FullScreenにする
	}

	m_hwnd = CreateWindow(					//Windowを開く
		m_applicationName,					//使用するWindowClass
		WindowDef::WindowName,				//Title名
		(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX),	//Resize禁止
		0, 0, WindowDef::ScreenWidth, WindowDef::ScreenHeight,							//位置、大きさ
		NULL, NULL, hInstance, NULL);

	if (m_hwnd == NULL)						//失敗したらFalseを返す
		return false;

	ShowWindow(m_hwnd, SW_SHOW);			//Windowを表示
	SetForegroundWindow(m_hwnd);			//一番上に表示
	SetFocus(m_hwnd);						//Windowを選択された状態のする
	ShowCursor(false);						//カーソル非表示

#pragma endregion
	
	m_InputState = std::make_shared<InputState>();
	if (!m_InputState)						//失敗したらFalseを返す
		return false;

	result = m_InputState->Initialize(m_hInstance, m_hwnd);			//Inputを初期化
	if (!result)
		return false;

	m_GraphicDevice = std::make_shared<GraphicDevice>();
	if (!m_GraphicDevice)
		return false;

	result = m_GraphicDevice->Initialize(m_hwnd);					//GraphicDeviceを初期化
	if (!result)
		return false;

	return true;
}

void Application::Run()
{
	MSG msg;								//Windowの状態メッセージ
	ZeroMemory(&msg, sizeof(MSG));			//msg初期化

	Initialize();							//Gameの初期化
	Load();									//ロードコンテンツ

	while (!IsEnd())						//終了しない限りGameLoop
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//Windowメッセージの確認
		{
			if (msg.message == WM_QUIT) break;			//終わるメッセージがあったらLoopから抜ける
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		if (!m_InputState->Update())		//InputState更新
			break;

		Update();							//Gameのアップデート
		Draw();								//Gameの描画処理
	}

	Unload();								//コンテンツ解放処理
	ShutDown();								//Windowのシャットダウン処理
}

void Application::ShutDown()
{
	if (m_GraphicDevice)								//GraphicDeviceをシャットダウン処理
	{
		m_GraphicDevice->Shutdown();
	}

	if(m_InputState)									//InputStateをシャットダウン処理
	{
		m_InputState->ShutDown();
	}

	ShowCursor(true);									//カーソル表示
	if (WindowDef::FullScreen) 
	{
		ChangeDisplaySettings(NULL, 0);					//Window化
	}

	DestroyWindow(m_hwnd);								//Windowを廃棄
	m_hwnd = NULL;

	UnregisterClass(m_applicationName, m_hInstance);	//登録したクラスを消す
	m_hInstance = NULL;
}

