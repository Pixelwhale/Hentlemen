#include <Core\DXGraphic.h>
#include <Def\WindowDef.h>

using namespace Core;

DXGraphic::DXGraphic()
{
	m_swapChain = 0;
	m_device = 0;
	m_deviceContext = 0;
	m_renderTargetView = 0;
	m_depthStencilBuffer = 0;
	m_depthStencilState = 0;
	m_depthStencilView = 0;
	m_rasterState = 0;
}

DXGraphic::DXGraphic(const DXGraphic&)
{
}

DXGraphic::~DXGraphic()
{
}


bool DXGraphic::Initialize(bool vsync, HWND hwnd)
{
#pragma region ���[�J���ϐ�
	HRESULT result;
	IDXGIFactory* factory;			//Interface DirectX Graphics Infrastructure(��b) Factory
	IDXGIAdapter* adapter;			//Adapter �A�_�v�^�[	�iVideo Card�j
	IDXGIOutput* adapterOutput;		//Adapter��Output		�i���j�^�[�j
			//�K������Mode���A��ʍX�V���֘A�A
	unsigned int numModes, numerator, denominator, stringLength;

	DXGI_MODE_DESC* displayModeList;		//�K������ModeList

	DXGI_ADAPTER_DESC adapterDesc;							//Video Card���
	DXGI_SWAP_CHAIN_DESC swapChainDesc;						//SwapChain

	D3D_FEATURE_LEVEL featureLevel;							//�g�p����DirectX�̃o�[�W����
	ID3D11Texture2D* backBufferPtr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
#pragma endregion

	m_vsync_enabled = vsync;

#pragma region VideoCard�����擾
	//Interface��ID�@IID
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);		//__uuidof() interface��uniqueID���Q�b�g
	if (FAILED(result))
		return false;															//�@DXGIFactory
																				//		��
	result = factory->EnumAdapters(0, &adapter);								//	adapter����
	if (FAILED(result))
		return false;															//		��

	result = adapter->EnumOutputs(0, &adapterOutput);							//	adapter��Output����
	if (FAILED(result))
		return false;
	//Fomat:RGBA 8bit unsigned normalized		//���j�^�[���w���Format���T�|�[�g���郂�[�h�̐�
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(result))
		return false;

	displayModeList = new DXGI_MODE_DESC[numModes];				//Mode�̐��Ŋi�[����List�����
	if (!displayModeList)
		return false;
	//List�Ɋi�[
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result))
		return false;

	for (int i = 0; i < numModes; i++)											//�𑜓x���K������Mode��T��
	{
		if (displayModeList[i].Width == WindowDef::ScreenWidth)
		{
			if (displayModeList[i].Height == WindowDef::ScreenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;			//��ʍX�V����ݒ�
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	result = adapter->GetDesc(&adapterDesc);											//Video Card�̏����擾
	if (FAILED(result))
		return false;

	m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);		//Video Card�̃��������L�^�imb�j
	//wcsrinbs_s ->�����^��ϊ��AVisual Studio 2017�Ŏg����
	wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128);		//Video Card�̖��O���L�^
#pragma endregion

#pragma region ���g�p�ϐ������

	delete displayModeList;
	displayModeList = 0;
	adapterOutput->Release();
	adapterOutput = 0;
	adapter->Release();
	adapter = 0;
	factory->Release();
	factory = 0;

#pragma endregion

#pragma region SwapChain�ݒ�
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));		//Initialize
															//Back Buffer��ݒ�
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = WindowDef::ScreenWidth;
	swapChainDesc.BufferDesc.Height = WindowDef::ScreenHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	if (m_vsync_enabled)					//Vertical Sync���L���̎��A��ʍX�V�������킹��
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	}
	else
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;					//�`��p�ɐݒ�iBackBuffer�j
	swapChainDesc.OutputWindow = hwnd;		//�`���
											//Multisampling�����i�L���̓|���S���̕ӂ��X���[�Y�j
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	if (WindowDef::FullScreen)				//FullScreen�ݒ�
	{
		swapChainDesc.Windowed = false;
	}
	else
	{
		swapChainDesc.Windowed = true;
	}

	//�|���S���̕`�揇�ƃT�C�Y�͎����ݒ肵�Ȃ�
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	//�`�悵�������
	swapChainDesc.Flags = false;
#pragma endregion

	featureLevel = D3D_FEATURE_LEVEL_11_0;		//DX11�ɂ���


}

void DXGraphic::Shutdown(){}

void DXGraphic::Begin(float, float, float, float){}
void DXGraphic::End(){}

//ID3D11Device* DXGraphic::GetDevice(){}
//ID3D11DeviceContext* DXGraphic::GetDeviceContext(){}

void DXGraphic::GetProjectionMatrix(D3DXMATRIX&){}
void DXGraphic::GetWorldMatrix(D3DXMATRIX&){}
void DXGraphic::GetOrthoMatrix(D3DXMATRIX&){}

void DXGraphic::GetVideoCardInfo(char*, int&){}