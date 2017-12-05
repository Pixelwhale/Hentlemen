#include <Core\InputState.h>
#include <Def\WindowDef.h>

using namespace Core;

InputState::InputState()
{
	m_directInput = 0;
	m_keyboard = 0;
	m_mouse = 0;
}

InputState::InputState(const InputState&)
{
}

InputState::~InputState()
{
}

bool InputState::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	m_mouseX = 0;
	m_mouseY = 0;

	result = DirectInput8Create(					//Initialize input Interface（デバイスの生成はこの後）
								hInstance,
								DIRECTINPUT_VERSION, IID_IDirectInput8,
								(void**)&m_directInput, NULL);
	if (FAILED(result))
		return false;

	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);			//キーボードデバイスを生成
	if (FAILED(result))
		return false;

	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
		return false;

	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);	//EXCLUSIVE(他のWindowに入力の影響が出ない)
	if (FAILED(result))
		return false;

	result = m_keyboard->Acquire();
	if (FAILED(result))
		return false;

	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);				//マウスデバイスを生成
	if (FAILED(result))
		return false;

	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
		return false;

	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);	//NONEXCLUSIVE(Windowを出ているか確認用)
	if (FAILED(result))
		return false;

	result = m_mouse->Acquire();
	if (FAILED(result))
		return false;

	return true;
}

void InputState::ShutDown()
{
	if (m_mouse)				//マウスを解放
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	if (m_keyboard)				//キーボードを解放
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	if (m_directInput)			//Interfaceを解放
	{
		m_directInput->Release();
		m_directInput = 0;
	}
}

bool InputState::Update()
{
	bool result;

	UpdateKeyboard();
	result = ReadKeyboard();
	if (!result)
		return false;

	result = ReadMouse();
	if (!result)
		return false;

	ClampMousePosition();

	return true;
}

bool InputState::ReadKeyboard()
{
	HRESULT result = m_keyboard->GetDeviceState(sizeof(m_ckeyboardState), (LPVOID)&m_ckeyboardState);

	if (result == DI_OK)		//Keyboard取得できたらTrue
	{
		return true;
	}

	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)	//他のWindowがメインなどの場合は取得を試みる
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;			//その他の場合
}

bool InputState::ReadMouse()
{
	HRESULT result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);

	if (result == DI_OK)		//Mouse取得できたらTrue
	{
		return true;
	}

	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)	//他のWindowがメインなどの場合は取得を試みる
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;			//その他の場合
}

void InputState::UpdateKeyboard()
{
	for (int i = 0; i < sizeof(m_ckeyboardState); i++)
	{
		m_pkeyboardState[i] = m_ckeyboardState[i];
	}
}

void InputState::ClampMousePosition()
{	
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY;

	if (m_mouseX < 0)
		m_mouseX = 0;
	if (m_mouseY < 0)
		m_mouseY = 0;

	if (m_mouseX > WindowDef::ScreenWidth)
		m_mouseX = WindowDef::ScreenWidth;
	if (m_mouseY > WindowDef::ScreenHeight)
		m_mouseY = WindowDef::ScreenHeight;
}

void InputState::MousePosition(int& mouseX, int& mouseY) 
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
}

bool InputState::IsKeyDown(unsigned int key)
{
	return m_ckeyboardState[key] & 0x80;
}

bool InputState::IsKeyTrigger(unsigned int key)
{
	return !(m_pkeyboardState[key] & 0x80) && m_ckeyboardState[key] & 0x80;
}