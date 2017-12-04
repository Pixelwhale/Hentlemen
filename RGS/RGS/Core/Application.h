//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.03�`2017.12.04
// ���e�@�FWindow�̊�{����
//-------------------------------------------------------
#pragma once
#include <Windows.h>

namespace Core
{
	class Application
	{
	public:
		virtual ~Application() {}
		/// <summary>Window�𐶐�����</summary>
		/// <param name="hInstance">Window���̂̃n���h��</param>  
		/// <returns>true:����, false:���s</returns>  
		bool InitWindow(HINSTANCE hInstance);

		/// <summary>�A�v���P�[�V�������N��</summary>
		void Run();

		/// <summary>Window��Ԃ̃��b�Z�[�W�n���h��</summary>
		/// <param name="hwnd">Window���̂̃n���h��</param>
		/// <param name="msg">��ԃ��b�Z�[�W</param>
		LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		/// <summary>�A�v���P�[�V�����̃V���b�g�_�E������</summary>
		void ShutDown();

	protected:
		/// <summary>����������</summary>
		virtual void Initialize() = 0;
		/// <summary>���\�[�X�ǂݍ��ޏ���</summary>
		virtual void Load() = 0;
		/// <summary>���\�[�X�������</summary>
		virtual void Unload() = 0;
		/// <summary>�X�V����</summary>
		virtual void Update() = 0;
		/// <summary>�`�揈��</summary>
		virtual void Draw() = 0;
		/// <summary>�I�����Ă��邩</summary>
		/// <returns>true:�I���, false:�I����ĂȂ�</returns>  
		virtual bool IsEnd() = 0;

	private:
		HINSTANCE m_hInstance;			//Program���̂̃n���h��
		LPCWSTR m_applicationName;		//�o�^����WindowClass�̖��O
		HWND m_hwnd;					//Window�̃n���h��
	};

	//Global
	static Application* ApplicationHandle = 0;

	/// <summary>Window��Ԃ̃��b�Z�[�W�n���h��</summary>
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:				//Window���p�����ꂽ�ꍇ
			PostQuitMessage(0);			//�I�����b�Z�[�W��m�点��
			return 0;
		case WM_CLOSE:					//Window��Close���ꂽ�ꍇ
			PostQuitMessage(0);			//�I�����b�Z�[�W��m�点��
			return 0;
		default:
			//���̑��̃��b�Z�[�W��Application��MessageHandler�ɓn��
			return ApplicationHandle->MessageHandler(hwnd, msg, wParam, lParam);
		}
	}
}