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
	ID3D11Texture2D* backBufferPtr;
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
	D3D11_RASTERIZER_DESC rasterDesc;
#pragma endregion

	m_vsync_enabled = vsync;

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

	for (int i = 0; i < numModes; i++)											//解像度が適合するModeを探す
	{
		if (displayModeList[i].Width == WindowDef::ScreenWidth)
		{
			if (displayModeList[i].Height == WindowDef::ScreenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;			//画面更新率を設定
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

	delete displayModeList;
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
#pragma endregion

	featureLevel = D3D_FEATURE_LEVEL_11_0;		//DX11にする


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