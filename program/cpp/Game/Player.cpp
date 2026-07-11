#include "header/Game/Player.h"
#include "header\Graphics\dx2.h"
#include "header/WindowState.h"
#include "header/Game/PlayerMove.h"

PlayerMove playerMove;

bool Player::Initialize()
{
    // プレイヤーの初期化処理をここに記述
     // D3DXCreateSprite関数を使用してスプライトを作成
    HRESULT result = D3DXCreateSprite(
        g_device,
        &playerSprite
    );
    //API関数の呼び出しが失敗した場合、falseを返す
    if (FAILED(result))
    {
        return false;
    }


    //PNG画像を読み込むためにD3DXCreateTextureFromFile関数を使用
    result = D3DXCreateTextureFromFile(
        g_device,
        "sorce\\soccer.png",
        &playerTexture
    );

    if (FAILED(result))
    {
        playerSprite->Release();
        playerSprite = nullptr;
        playerTexture = nullptr;
        return false;
    }

    return SUCCEEDED(result);
	return true;
}


void Player::Update()
{
    playerMove.Update();
}

void Player::Finalize()
{
    // プレイヤーの終了処理をここに記述
    if (playerTexture != nullptr)
    {
        playerTexture->Release();
        playerTexture = nullptr;
    }

    if (playerSprite != nullptr)
    {
        playerSprite->Release();
        playerSprite = nullptr;
    }
}

void Player::OnLostDevice()
{
    if (playerSprite != nullptr)
    {
        playerSprite->OnLostDevice();
    }
}

void Player::OnResetDevice()
{
    if (playerSprite != nullptr)
    {
        playerSprite->OnResetDevice();
    }
}

float Player::GetScaleX() const
{
    return scaleX;
}

float Player::GetScaleY() const
{
    return scaleY;
}


