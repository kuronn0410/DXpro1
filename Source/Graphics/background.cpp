#include "Window/WindowState.h"
#include "Graphics/dx2.h"

#include "Graphics/background.h"

bool Background::Initialize()
{

    if (!sprite.Init(
        g_device,
        "Assets\\Textures\\Shiba.png"))
    {
        return false;
    }
    imageInfo = sprite.GetImageInfo();
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width);
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height);

    return true;
}

void Background::Draw()
{
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width);
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height);

    sprite.Draw(0, 0, scaleX, scaleY);
	
}

//一度画像を外すときに呼び出す関数
void Background::OnLostDevice()
{
    /*if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnLostDevice();
    }*/
    
}

//大きさを変えたときに画像をもう一度設定する
void Background::OnResetDevice()
{
    /*if (backgroundSprite != nullptr)
    {
        backgroundSprite->OnResetDevice();
    }*/
}
void Background::Finalize()
{
	sprite.Release();
	
}