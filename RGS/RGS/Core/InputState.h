//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.05
// 内容　：入力処理
//-------------------------------------------------------
#pragma once
#include <DX\Include\dinput.h>

namespace Core 
{
	class InputState 
	{
	public:
		InputState();
		InputState(const InputState&);
		~InputState();

		bool Initialize(HINSTANCE hInstance, HWND hwnd);
		void ShutDown();
		bool Update();

		void MousePosition(int&, int&);

		bool IsKeyDown(unsigned int key);
		bool IsKeyTrigger(unsigned int key);

	private:
		bool ReadKeyboard();
		bool ReadMouse();
		void ClampMousePosition();
		void UpdateKeyboard();

	private:
		IDirectInput8* m_directInput;
		IDirectInputDevice8* m_keyboard;
		IDirectInputDevice8* m_mouse;

		unsigned char m_ckeyboardState[256];
		unsigned char m_pkeyboardState[256];
		DIMOUSESTATE m_mouseState;
		int m_mouseX, m_mouseY;
	};
}