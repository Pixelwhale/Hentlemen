//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.03
// 内容　：Windowの基本処理
//-------------------------------------------------------
#pragma once
#include <Windows.h>

namespace Core 
{
	class Application
	{
	public:
		virtual ~Application() {}
		bool InitWindow(HINSTANCE hInstance);
		void Run();
		void ShutDown();

		LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		virtual void Initialize() = 0;
		virtual void Load() = 0;
		virtual void Unload() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual bool IsEnd() = 0;

	private:
		HINSTANCE m_hInstance;
		LPCWSTR m_applicationName;
		HWND m_hwnd;
	};

	//Function Prototype
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	//Global
	static Application* ApplicationHandle = 0;
}