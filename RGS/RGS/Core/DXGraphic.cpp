//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04�`2017.12.09
// ���e�@�FDX��Library�ł܂Ƃ߂��`��֐�
//-------------------------------------------------------
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

bool DXGraphic::Initialize(HWND hwnd)
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
	ID3D11Texture2D* backBufferPtr;							//BackBuffer��Pointer
	D3D11_TEXTURE2D_DESC depthBufferDesc;					//DepthBuffer�̐ݒ�
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;				//DepthStencil�̐ݒ�
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;								//ViewPort
	float fieldOfView, screenAspect;						//FOV, Aspect
#pragma endregion

	m_vsync_enabled = WindowDef::Vsync;

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

	for (unsigned int i = 0; i < numModes; i++)											//�𑜓x���K������Mode��T��
	{
		if (displayModeList[i].Width == WindowDef::ScreenWidth)
		{
			if (displayModeList[i].Height == WindowDef::ScreenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;					//��ʍX�V����ݒ�
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

	delete[] displayModeList;
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

	featureLevel = D3D_FEATURE_LEVEL_11_0;			//DX11�ɂ���

	result = D3D11CreateDeviceAndSwapChain(			//SwapChain��DeviceContext�𐶐�
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,					//DX11�T�|�[�g���Ȃ�������Reference�ɂ���@CPU�ŕ`��
		NULL, 0,
		&featureLevel, 1,
		D3D11_SDK_VERSION,
		&swapChainDesc, &m_swapChain, &m_device,
		NULL, &m_deviceContext);
	if (FAILED(result))
		return false;

	//BackBuffer��SwapChain�ɐݒ�
	result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
	if (FAILED(result))
		return false;

	//BackBuffer��RenderTarget�𐶐�
	result = m_device->CreateRenderTargetView(backBufferPtr, NULL, &m_renderTargetView);
	if (FAILED(result))
		return false;

	//BackBuffer��Pointer�����
	backBufferPtr->Release();
	backBufferPtr = 0;
#pragma endregion

	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));					//������
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));				//������
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));		//������

#pragma region DepthBuffer�ݒ�
	depthBufferDesc.Width = WindowDef::ScreenWidth;
	depthBufferDesc.Height = WindowDef::ScreenHeight;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthBufferDesc.SampleDesc.Count = 1;
	depthBufferDesc.SampleDesc.Quality = 0;
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;
#pragma endregion

	result = m_device->CreateTexture2D(&depthBufferDesc, NULL, &m_depthStencilBuffer);		//DepthBuffer�̃e�N�X�`���𐶐�
	if (FAILED(result))
		return false;

#pragma region DepthStencil�ݒ�

	//Depth Test
	depthStencilDesc.DepthEnable = true;										//�[�x�L��
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;				//�[�x�ւ̏������ݗL��
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;							//�[�x������������������
																				//Stencil Test
	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;
	//Stencil operations front-facing�i���ʁj
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;			//Stencil���s�@�����f�[�^�ێ�
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;		//Stencil���iDepth���s�@Stencil+1
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;			//�������i�@�����f�[�^�ێ�
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;			//��r���@�@����
																				//Stencil operations back-facing�i�w�ʁj
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

#pragma endregion

	result = m_device->CreateDepthStencilState(&depthStencilDesc, &m_depthStencilState);	//DepthStencil�𐶐�
	if (FAILED(result))
		return false;

#pragma region DepthStencilView�ݒ�

	m_deviceContext->OMSetDepthStencilState(m_depthStencilState, 1);
	//Depth24 unsigned normalize Stencil8 unsigned int
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;			//2DTexture�Ƃ���
	depthStencilViewDesc.Texture2D.MipSlice = 0;
#pragma endregion

	result = m_device->CreateDepthStencilView(m_depthStencilBuffer, &depthStencilViewDesc, &m_depthStencilView);
	if (FAILED(result))
		MessageBox(hwnd, TEXT("DepthStencilView Failed to Create"), TEXT("ERROR"), MB_OK);

	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);		//RenderTarget��DepthStencil���o�C���h

#pragma region Rasterizer�ݒ�

	rasterDesc.AntialiasedLineEnable = false;			//���̃A���`�G�C���A�V���O��ݒ�
	rasterDesc.CullMode = D3D11_CULL_BACK;				//�w�ʃJ�[�����O
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;				//Solid <==> Wireframe
	rasterDesc.FrontCounterClockwise = false;			//�J�[�����O���ʐݒ�
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

#pragma endregion

	result = m_device->CreateRasterizerState(&rasterDesc, &m_rasterState);					//Rasterizer�𐶐�	
	if (FAILED(result))
		return false;

	m_deviceContext->RSSetState(m_rasterState);

#pragma region Viewport�ݒ�

	viewport.Width = WindowDef::ScreenWidth;
	viewport.Height = WindowDef::ScreenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

#pragma endregion

	m_deviceContext->RSSetViewports(1, &viewport);

#pragma region Projection�ݒ�

	fieldOfView = (float)D3DX_PI / 4.0f;
	screenAspect = (float)WindowDef::ScreenWidth / (float)WindowDef::ScreenHeight;
	D3DXMatrixPerspectiveFovLH(&m_projectionMatrix, fieldOfView, screenAspect, 0.1f, 1000.0f);				//3D
	D3DXMatrixIdentity(&m_worldMatrix);			//WorldMatrix������
	D3DXMatrixOrthoLH(&m_orthoMatrix, (float)WindowDef::ScreenWidth, (float)WindowDef::ScreenHeight, 0.1f, 1000.0f);		//2D

#pragma endregion

	return true;
}


void DXGraphic::Shutdown()
{
	if (m_swapChain)
		m_swapChain->SetFullscreenState(false, NULL);		//Window�����Ă���Release

	if (m_rasterState)										//���X�^���C�YState��Release
	{
		m_rasterState->Release();
		m_rasterState = 0;
	}

	if (m_depthStencilView)									//DepthStencilView��Release
	{
		m_depthStencilView->Release();
		m_depthStencilView = 0;
	}

	if (m_depthStencilState)								//DepthStencilState��Release
	{
		m_depthStencilState->Release();
		m_depthStencilState = 0;
	}

	if (m_depthStencilBuffer)								//DepthStencilBuffer��Release
	{
		m_depthStencilBuffer->Release();
		m_depthStencilBuffer = 0;
	}

	if(m_renderTargetView)									//RenderTarget��Release
	{
		m_renderTargetView->Release();
		m_renderTargetView = 0;
	}

	if (m_deviceContext)									//DeviceContext��Release
	{
		m_deviceContext->Release();
		m_deviceContext = 0;
	}

	if (m_device)											//Device��Release
	{
		m_device->Release();
		m_device = 0;
	}

	if (m_swapChain)										//SwapChain��Release
	{
		m_swapChain->Release();
		m_swapChain = 0;
	}
}

void DXGraphic::Begin(float r, float g, float b, float a)
{
	float color[4];
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;

	//Clear Color�ݒ�AClear Depth���
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, color);
	m_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DXGraphic::End()
{
	if (m_vsync_enabled)
	{
		m_swapChain->Present(1, 0);			//��ʍX�V���ɍ��킹�ĕ`��
	}
	else
	{
		m_swapChain->Present(0, 0);			//��������������`��i�������Ȃ��j
	}
}

ID3D11Device* DXGraphic::GetDevice()
{
	return m_device;
}

ID3D11DeviceContext* DXGraphic::GetDeviceContext()
{
	return m_deviceContext;
}

void DXGraphic::GetProjectionMatrix(D3DXMATRIX& projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
}

void DXGraphic::GetWorldMatrix(D3DXMATRIX& worldMatrix)
{
	worldMatrix = m_worldMatrix;
}

void DXGraphic::GetOrthoMatrix(D3DXMATRIX& orthoMatrix)
{
	orthoMatrix = m_orthoMatrix;
}

void DXGraphic::GetVideoCardInfo(char* cardName, int& memory)
{
	strcpy_s(cardName, 128, m_videoCardDescription);
	memory = m_videoCardMemory;
}