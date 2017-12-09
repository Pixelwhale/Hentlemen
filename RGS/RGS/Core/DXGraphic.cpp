//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04～2017.12.09
// 内容　：DXのLibraryでまとめた描画関数
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
#pragma region ローカル変数
	HRESULT result;
	IDXGIFactory* factory;			//Interface DirectX Graphics Infrastructure(基礎) Factory
	IDXGIAdapter* adapter;			//Adapter アダプター	（Video Card）
	IDXGIOutput* adapterOutput;		//AdapterのOutput		（モニター）
			//適合するMode数、画面更新率関連、
	unsigned int numModes, numerator, denominator, stringLength;

	DXGI_MODE_DESC* displayModeList;		//適合するModeList

	DXGI_ADAPTER_DESC adapterDesc;							//Video Card情報
	DXGI_SWAP_CHAIN_DESC swapChainDesc;						//SwapChain

	D3D_FEATURE_LEVEL featureLevel;							//使用するDirectXのバージョン
	ID3D11Texture2D* backBufferPtr;							//BackBufferのPointer
	D3D11_TEXTURE2D_DESC depthBufferDesc;					//DepthBufferの設定
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;				//DepthStencilの設定
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
	D3D11_VIEWPORT viewport;								//ViewPort
	float fieldOfView, screenAspect;						//FOV, Aspect
#pragma endregion

	m_vsync_enabled = WindowDef::Vsync;

#pragma region VideoCard情報を取得
	//InterfaceのID　IID
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);		//__uuidof() interfaceのuniqueIDをゲット
	if (FAILED(result))
		return false;															//　DXGIFactory
																				//		↓
	result = factory->EnumAdapters(0, &adapter);								//	adapter生成
	if (FAILED(result))
		return false;															//		↓

	result = adapter->EnumOutputs(0, &adapterOutput);							//	adapterのOutput生成
	if (FAILED(result))
		return false;
	//Fomat:RGBA 8bit unsigned normalized		//モニターが指定のFormatをサポートするモードの数
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(result))
		return false;

	displayModeList = new DXGI_MODE_DESC[numModes];				//Modeの数で格納するListを作る
	if (!displayModeList)
		return false;
	//Listに格納
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result))
		return false;

	for (unsigned int i = 0; i < numModes; i++)											//解像度が適合するModeを探す
	{
		if (displayModeList[i].Width == WindowDef::ScreenWidth)
		{
			if (displayModeList[i].Height == WindowDef::ScreenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;					//画面更新率を設定
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	result = adapter->GetDesc(&adapterDesc);											//Video Cardの情報を取得
	if (FAILED(result))
		return false;

	m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);		//Video Cardのメモリを記録（mb）
	//wcsrinbs_s ->文字型を変換、Visual Studio 2017で使える
	wcstombs_s(&stringLength, m_videoCardDescription, 128, adapterDesc.Description, 128);		//Video Cardの名前を記録
#pragma endregion

#pragma region 未使用変数を解放

	delete[] displayModeList;
	displayModeList = 0;
	adapterOutput->Release();
	adapterOutput = 0;
	adapter->Release();
	adapter = 0;
	factory->Release();
	factory = 0;

#pragma endregion

#pragma region SwapChain設定
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));		//Initialize
															//Back Buffer一つ設定
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = WindowDef::ScreenWidth;
	swapChainDesc.BufferDesc.Height = WindowDef::ScreenHeight;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	if (m_vsync_enabled)					//Vertical Syncが有効の時、画面更新率を合わせる
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = numerator;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = denominator;
	}
	else
	{
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	}
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;					//描画用に設定（BackBuffer）
	swapChainDesc.OutputWindow = hwnd;		//描画先
											//Multisampling無効（有効はポリゴンの辺がスムーズ）
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	if (WindowDef::FullScreen)				//FullScreen設定
	{
		swapChainDesc.Windowed = false;
	}
	else
	{
		swapChainDesc.Windowed = true;
	}

	//ポリゴンの描画順とサイズは自動設定しない
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	//描画したら放棄
	swapChainDesc.Flags = false;

	featureLevel = D3D_FEATURE_LEVEL_11_0;			//DX11にする

	result = D3D11CreateDeviceAndSwapChain(			//SwapChainとDeviceContextを生成
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,					//DX11サポートしなかったらReferenceにする　CPUで描画
		NULL, 0,
		&featureLevel, 1,
		D3D11_SDK_VERSION,
		&swapChainDesc, &m_swapChain, &m_device,
		NULL, &m_deviceContext);
	if (FAILED(result))
		return false;

	//BackBufferをSwapChainに設定
	result = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
	if (FAILED(result))
		return false;

	//BackBufferにRenderTargetを生成
	result = m_device->CreateRenderTargetView(backBufferPtr, NULL, &m_renderTargetView);
	if (FAILED(result))
		return false;

	//BackBufferのPointerを解放
	backBufferPtr->Release();
	backBufferPtr = 0;
#pragma endregion

	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));					//初期化
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));				//初期化
	ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));		//初期化

#pragma region DepthBuffer設定
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

	result = m_device->CreateTexture2D(&depthBufferDesc, NULL, &m_depthStencilBuffer);		//DepthBufferのテクスチャを生成
	if (FAILED(result))
		return false;

#pragma region DepthStencil設定

	//Depth Test
	depthStencilDesc.DepthEnable = true;										//深度有効
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;				//深度への書き込み有効
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;							//深度が小さい方書き込む
																				//Stencil Test
	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;
	//Stencil operations front-facing（正面）
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;			//Stencil失敗　既存データ保持
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;		//Stencil合格Depth失敗　Stencil+1
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;			//両方合格　既存データ保持
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;			//比較方法　いつも
																				//Stencil operations back-facing（背面）
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

#pragma endregion

	result = m_device->CreateDepthStencilState(&depthStencilDesc, &m_depthStencilState);	//DepthStencilを生成
	if (FAILED(result))
		return false;

#pragma region DepthStencilView設定

	m_deviceContext->OMSetDepthStencilState(m_depthStencilState, 1);
	//Depth24 unsigned normalize Stencil8 unsigned int
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;			//2DTextureとして
	depthStencilViewDesc.Texture2D.MipSlice = 0;
#pragma endregion

	result = m_device->CreateDepthStencilView(m_depthStencilBuffer, &depthStencilViewDesc, &m_depthStencilView);
	if (FAILED(result))
		MessageBox(hwnd, TEXT("DepthStencilView Failed to Create"), TEXT("ERROR"), MB_OK);

	m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, m_depthStencilView);		//RenderTargetとDepthStencilをバインド

#pragma region Rasterizer設定

	rasterDesc.AntialiasedLineEnable = false;			//線のアンチエイリアシングを設定
	rasterDesc.CullMode = D3D11_CULL_BACK;				//背面カーリング
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;				//Solid <==> Wireframe
	rasterDesc.FrontCounterClockwise = false;			//カーリング正面設定
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

#pragma endregion

	result = m_device->CreateRasterizerState(&rasterDesc, &m_rasterState);					//Rasterizerを生成	
	if (FAILED(result))
		return false;

	m_deviceContext->RSSetState(m_rasterState);

#pragma region Viewport設定

	viewport.Width = WindowDef::ScreenWidth;
	viewport.Height = WindowDef::ScreenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

#pragma endregion

	m_deviceContext->RSSetViewports(1, &viewport);

#pragma region Projection設定

	fieldOfView = (float)D3DX_PI / 4.0f;
	screenAspect = (float)WindowDef::ScreenWidth / (float)WindowDef::ScreenHeight;
	D3DXMatrixPerspectiveFovLH(&m_projectionMatrix, fieldOfView, screenAspect, 0.1f, 1000.0f);				//3D
	D3DXMatrixIdentity(&m_worldMatrix);			//WorldMatrix初期化
	D3DXMatrixOrthoLH(&m_orthoMatrix, (float)WindowDef::ScreenWidth, (float)WindowDef::ScreenHeight, 0.1f, 1000.0f);		//2D

#pragma endregion

	return true;
}


void DXGraphic::Shutdown()
{
	if (m_swapChain)
		m_swapChain->SetFullscreenState(false, NULL);		//Window化してからRelease

	if (m_rasterState)										//ラスタライズStateをRelease
	{
		m_rasterState->Release();
		m_rasterState = 0;
	}

	if (m_depthStencilView)									//DepthStencilViewをRelease
	{
		m_depthStencilView->Release();
		m_depthStencilView = 0;
	}

	if (m_depthStencilState)								//DepthStencilStateをRelease
	{
		m_depthStencilState->Release();
		m_depthStencilState = 0;
	}

	if (m_depthStencilBuffer)								//DepthStencilBufferをRelease
	{
		m_depthStencilBuffer->Release();
		m_depthStencilBuffer = 0;
	}

	if(m_renderTargetView)									//RenderTargetをRelease
	{
		m_renderTargetView->Release();
		m_renderTargetView = 0;
	}

	if (m_deviceContext)									//DeviceContextをRelease
	{
		m_deviceContext->Release();
		m_deviceContext = 0;
	}

	if (m_device)											//DeviceをRelease
	{
		m_device->Release();
		m_device = 0;
	}

	if (m_swapChain)										//SwapChainをRelease
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

	//Clear Color設定、Clear Depth情報
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, color);
	m_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DXGraphic::End()
{
	if (m_vsync_enabled)
	{
		m_swapChain->Present(1, 0);			//画面更新率に合わせて描画
	}
	else
	{
		m_swapChain->Present(0, 0);			//処理が完了次第描画（制限がない）
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