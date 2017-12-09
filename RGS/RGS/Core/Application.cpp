//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03～2017.12.04
// 内容　：Windowの基本処理
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

#pragma region DxLib初期化
	SetOutApplicationLogValidFlag(false);			//Logを書き出ししない
	SetWindowText(WindowDef::WindowName);			//Title設定
	SetGraphMode(
		WindowDef::ScreenWidth,						//WindowSize
		WindowDef::ScreenHeight,
		32, 60);									//Color 32bit  60Frame
	ChangeWindowMode(WindowDef::IsWindow);			//全画面設定
	DxLib_Init();									//DXLibrary初期化
	SetMouseDispFlag(false);						//Mouse表示しない

	m_hwnd = DxLib::GetMainWindowHandle();			//WindowHandleを取得
	m_hInstance = DxLib::GetTaskInstance();			//Programの実体を取得

#pragma endregion

#pragma region InputState初期化

	m_InputState = std::make_shared<InputState>();
	if (!m_InputState)						//失敗したらFalseを返す
		return false;

	result = m_InputState->Initialize(m_hInstance, m_hwnd);			//Inputを初期化
	if (!result)
		return false;

#pragma endregion

#pragma region Renderer初期化

	m_Renderer = std::make_shared<Device::Renderer>();
	m_Renderer->Initialize();

#pragma endregion

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
	SetMouseDispFlag(true);								//Mouse表示

	if (m_InputState)									//InputStateをシャットダウン処理
	{
		m_InputState->ShutDown();
		m_InputState = 0;
	}

	if (m_Renderer)
	{
		m_Renderer->Release();
		m_Renderer = 0;
	}

	DxLib_End();										//DXLib終了処理
}

