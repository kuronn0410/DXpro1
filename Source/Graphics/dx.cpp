//実体をつくって保存する

#include "Graphics/dx2.h"

IDirect3D9* g_direct3D = nullptr;// Direct3D9オブジェクトのポインタを保持する
IDirect3DDevice9* g_device = nullptr;// Direct3D9デバイスのポインタを保持する
static D3DPRESENT_PARAMETERS g_params = {};

bool DirectXInitialize(HWND window)
{
	//SDKのバージョンを伝えて帰ってきたDirect3D9オブジェクトを登録する
    g_direct3D = Direct3DCreate9(D3D_SDK_VERSION);

    if (g_direct3D == nullptr)
        return false;

	//どのような設定でｗindowsに描画するかを設定する
   
    g_params = {};
    g_params.Windowed = TRUE; //ウィンドウモード （FALSE = フルスクリーン）
    g_params.SwapEffect = D3DSWAPEFFECT_DISCARD;//表示が終わった古い描画画面は、再利用せず破棄してよいという設定
    g_params.hDeviceWindow = window;
    g_params.BackBufferFormat = D3DFMT_UNKNOWN;
    g_params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    //その設定で実際の描画環境を作る
    HRESULT result = g_direct3D->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        window,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &g_params,
        &g_device
    );

    return SUCCEEDED(result);
}

// ウィンドウサイズ変更時に呼び出す関数
//実行結果をboolで返す
bool DirectXResize(int width, int height)
{
    if (g_device == nullptr || width <= 0 || height <= 0)
    {
        return false;
    }

    g_params.BackBufferWidth = width;
    g_params.BackBufferHeight = height;

    return SUCCEEDED(g_device->Reset(&g_params));
}

//、1フレーム分の描画を開始する準備
void DrawBegin()
{
    if (g_device == nullptr) return;

    g_device->Clear(
        0, 
        nullptr,
        D3DCLEAR_TARGET,
        D3DCOLOR_XRGB(0, 0, 0),
        1.0f, 
        0
    );

    g_device->BeginScene();
}


void DrawEnd()
{
    if (g_device == nullptr) return;

    g_device->EndScene();
    g_device->Present(nullptr, nullptr, nullptr, nullptr);
}

void DirectXFinalize()
{
    if (g_device != nullptr)
    {
        g_device->Release();
        g_device = nullptr;
    }

    if (g_direct3D != nullptr)
    {
        g_direct3D->Release();
        g_direct3D = nullptr;
    }
}