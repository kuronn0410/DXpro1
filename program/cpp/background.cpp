#include "header\WindowState.h"
#include "header\dx2.h"

#pragma region ”wŒi•`‰æ—p
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
	// ”wŒi‚Ì•`‰æˆ—‚ð‚±‚±‚É‹Lq
    if (backgroundSprite == nullptr ||
        backgroundTexture == nullptr)
    {
        return;
    }

    D3DSURFACE_DESC imageInfo = {};
    backgroundTexture->GetLevelDesc(0, &imageInfo);

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

//ˆê“x‰æ‘œ‚ðŠO‚·‚Æ‚«‚ÉŒÄ‚Ño‚·ŠÖ”
void BackgroundOnLostDevice()
{
    if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnLostDevice();
    }
}

//‘å‚«‚³‚ð•Ï‚¦‚½‚Æ‚«‚É‰æ‘œ‚ð‚à‚¤ˆê“xÝ’è‚·‚é
void BackgroundOnResetDevice()
{
    if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnResetDevice();
    }
}
void BackgroundFinalize()
{
	// ”wŒi‚ÌI—¹ˆ—‚ð‚±‚±‚É‹Lq
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