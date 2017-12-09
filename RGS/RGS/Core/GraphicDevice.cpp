//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04～2017.12.09
// 内容　：レンダラー
//-------------------------------------------------------
#include <Core\GraphicDevice.h>
#include <Def\WindowDef.h>

using namespace Core;

GraphicDevice::GraphicDevice()
{
	m_DXDevice = 0;
}

GraphicDevice::GraphicDevice(const GraphicDevice& graphicDevice)
{
}

GraphicDevice::~GraphicDevice()
{
}

bool GraphicDevice::Initialize(HWND hwnd)
{
	bool result;

	m_DXDevice = std::make_shared<DXGraphic>();
	if (!m_DXDevice)
		return false;

	result = m_DXDevice->Initialize(hwnd);				//初期化処理
	if (!result) 
	{
		MessageBox(hwnd, TEXT("Initialize失敗"), TEXT("Error"), MB_OK);
		return false;
	}

	return true;
}

void GraphicDevice::Shutdown()
{
	if (m_DXDevice)
	{
		m_DXDevice->Shutdown();
		m_DXDevice = 0;
	}
}

void GraphicDevice::StartRender(float r, float g, float b, float a)
{
	m_DXDevice->Begin(r, g, b, a);			//ClearColor設定
}

void GraphicDevice::EndRender()
{
	m_DXDevice->End();						//SwapBuffer
}