//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04�`2017.12.09
// ���e�@�F�����_���[
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

	result = m_DXDevice->Initialize(hwnd);				//����������
	if (!result) 
	{
		MessageBox(hwnd, TEXT("Initialize���s"), TEXT("Error"), MB_OK);
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
	m_DXDevice->Begin(r, g, b, a);			//ClearColor�ݒ�
}

void GraphicDevice::EndRender()
{
	m_DXDevice->End();						//SwapBuffer
}