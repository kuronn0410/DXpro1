#include "header\WindowState.h"
#include "header\Graphics\dx2.h"

#pragma region 背景描画用
static IDirect3DTexture9* backgroundTexture = nullptr;
static ID3DXSprite* backgroundSprite = nullptr;
#pragma endregion

bool BackgroundInitialize()
{
    HRESULT result = D3DXCreateSprite(
        g_device,
        &backgroundSprite
    );

    if (FAILED(result))
    {
        return false;
    }
    //登録
    result = D3DXCreateTextureFromFile(
        g_device,
        "sorce\\Shiba.png",
        &backgroundTexture
    );

    if (FAILED(result))
    {
        backgroundSprite->Release();
        backgroundSprite = nullptr;
        return false;
    }

    return true;
}

void BackgroundDraw()
{
	// 背景の描画処理をここに記述
    if (backgroundSprite == nullptr ||
        backgroundTexture == nullptr)
    {
        return;
    }
	//画像を保存するための構造体を作成
    D3DSURFACE_DESC imageInfo = {};
    //登録済みの画像から情報を取得
    backgroundTexture->GetLevelDesc(0, &imageInfo);

	//ウィンドウの幅と高さを画像の幅と高さで割ってスケーリングする
    float scaleX =
        static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width);

    float scaleY =
        static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height);

    D3DXMATRIX scaleMatrix;
    D3DXMatrixScaling(
        &scaleMatrix,
        scaleX,
        scaleY,
        0.5f
    );

    backgroundSprite->Begin(D3DXSPRITE_ALPHABLEND);
    backgroundSprite->SetTransform(&scaleMatrix);

    backgroundSprite->Draw(
        backgroundTexture,
        nullptr,
        nullptr,
        nullptr,
        D3DCOLOR_XRGB(255, 255, 255)
    );

    backgroundSprite->End();
}

//一度画像を外すときに呼び出す関数
void BackgroundOnLostDevice()
{
    if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnLostDevice();
    }
}

//大きさを変えたときに画像をもう一度設定する
void BackgroundOnResetDevice()
{
    if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnResetDevice();
    }
}
void BackgroundFinalize()
{
	// 背景の終了処理をここに記述
    if (backgroundTexture != nullptr)
    {
        backgroundTexture->Release();
        backgroundTexture = nullptr;
    }

    if (backgroundSprite != nullptr)
    {
        backgroundSprite->Release();
        backgroundSprite = nullptr;
    }
}