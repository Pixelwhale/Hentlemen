//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.05
// ���e�@�F���͏���
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

		///	<summary>������</summary>
		/// <param name="hInstance">Program���̂̃n���h��</param>  
		/// <param name="hwnd">Window�̃n���h��</param> 
		/// <returns>true:�����Afalse:���s</returns>
		bool Initialize(HINSTANCE hInstance, HWND hwnd);
		///	<summary>�V���b�g�_�E������</summary>
		void ShutDown();
		///	<summary>�X�V����</summary>
		bool Update();

		///	<summary>�}�E�X�̈ʒu���擾</summary>
		/// <param name="mouseX">X���W</param>  
		/// <param name="mouseY">Y���W</param> 
		void MousePosition(int& mouse_x, int& mouse_y);

		///	<summary>�w��̃L�[��������Ă��邩</summary>
		/// <param name="dik_key">DirectInputKey:DIK_�w��̃L�[</param>  
		bool IsKeyDown(unsigned int dik_key);
		///	<summary>�w��̃L�[�����̃t���[���ŉ�����Ă��邩</summary>
		/// <param name="dik_key">DirectInputKey:DIK_�w��̃L�[</param>  
		bool IsKeyTrigger(unsigned int dik_key);

	private:
		///	<summary>KeyState�̍X�V</summary>
		/// <returns>true:�����Afalse:���s</returns>
		bool ReadKeyboard();
		///	<summary>�}�E�X�̈ʒu���X�V</summary>
		/// <returns>true:�����Afalse:���s</returns>
		bool ReadMouse();
		///	<summary>�}�E�X�̈ʒu����ʓ���Clamp</summary>
		void ClampMousePosition();
		///	<summary>�O�t���[����KeyState���X�V</summary>
		void UpdateKeyboard();

	private:
		IDirectInput8* m_directInput;				//Input Device
		IDirectInputDevice8* m_keyboard;			//Keyboard Device
		IDirectInputDevice8* m_mouse;				//Mouse Device

		unsigned char m_ckeyboardState[256];		//���̃t���[����KeyState
		unsigned char m_pkeyboardState[256];		//�O�t���[����KeyState
		DIMOUSESTATE m_mouseState;					//MouseState
		int m_mouseX, m_mouseY;						//Mouse�̈ʒu
	};
}