#pragma once
#include <Windows.h>
#include <Core\DXGraphic.h>

namespace Core
{
	class GraphicDevice
	{
	public:
		GraphicDevice();
		GraphicDevice(const GraphicDevice&);
		~GraphicDevice();

		bool Initialize(int, int, HWND);
		void Shutdown();

		void StartRender();
		void EndRender();
	};
}