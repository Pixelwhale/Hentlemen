//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03〜2017.12.04
// 内容　：Windowの基本処理
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

#pragma region DxLib初期化
	SetOutApplicationLogValidFlag(false);			//Logを書き出ししない
	SetWindowText(WindowDef::kWindowName);			//Title設定
	SetGraphMode(
		WindowDef::kScreenWidth,						//WindowSize
		WindowDef::kScreenHeight,
		32, 60);									//Color 32bit  60Frame
	ChangeWindowMode(WindowDef::kIsWindow);			//全画面設定
	DxLib_Init();									//DXLibrary初期化
	SetMouseDispFlag(false);						//Mouse表示しない

	m_hwnd = DxLib::GetMainWindowHandle();			//WindowHandleを取得
	m_hInstance = DxLib::GetTaskInstance();			//Programの実体を取得

#pragma endregion

#pragma region InputState初期化

	m_inputState = std::make_shared<InputState>();
	if (!m_inputState)						//失敗したらFalseを返す
		return false;

	result = m_inputState->Initialize(m_hInstance, m_hwnd);			//Inputを初期化
	if (!result)
		return false;

#pragma endregion

#pragma region ContentManager初期化
	m_contentManager = std::make_shared<Device::ContentManager>();
	m_contentManager->Initialize();
#pragma endregion

#pragma region Renderer初期化

	m_renderer = std::make_shared<Device::Renderer>(m_contentManager);
	m_renderer->Initialize();

#pragma endregion

	return true;
}

void Application::Run()
{
	MSG msg;								//Windowの状態メッセージ
	ZeroMemory(&msg, sizeof(MSG));			//msg初期化

	Initialize();							//Gameの初期化
	Load();									//ロードコンテンツ

	while (ProcessMessage()== 0 && !IsEnd())						//終了しない限りGameLoop
	{
		if (!m_inputState->Update())		//InputState更新
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

	if (m_inputState)									//InputStateをシャットダウン処理
	{
		m_inputState->ShutDown();
		m_inputState = 0;
	}

	if (m_renderer)										//Rendererをシャットダウン処理
	{
		m_renderer->Release();
		m_renderer = 0;
	}

	if (m_contentManager) 								//Contentをシャットダウン処理
	{
		m_contentManager->Release();
		m_contentManager = 0;
	}

	DxLib_End();										//DXLib終了処理
}

