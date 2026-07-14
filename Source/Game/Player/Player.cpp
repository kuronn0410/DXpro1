#include "Game/Player/Player.h"
//#include "Window/WindowState.h"
#include "Game/Player/PlayerMove.h"

PlayerMove playerMove;

bool Player::Initialize()
{
    /*
    スプライト作成
    作成したスプライトに

    */
    // DirectXにスプライトを作ってもらい、その結果を playerSprite に入れてもらう
    HRESULT result = D3DXCreateSprite(
        g_device,//g_deviceが管理している描画環境を使って
        &playerSprite // 作ったSpriteのアドレスをplayerSpriteに入れてもらう
    );

    //API関数の呼び出しが失敗した場合、falseを返す
    if (FAILED(result))
    {
        return false;
    }

    //PNG画像を読み込むためにD3DXCreateTextureFromFile関数を使用
    result = D3DXCreateTextureFromFile(
        g_device,//g_deviceが管理している描画環境を使って
        "Assets\\Textures\\soccer.png",//読み込むPNG画像のパスを指定
		&playerTexture//作ったTextureのアドレスをplayerTextureに入れてもらう
    );

    if (FAILED(result))
    {
        playerSprite->Release();
        playerSprite = nullptr;
        playerTexture = nullptr;
        return false;
    }

    //playerTextureが示してる画像の情報を取得して構造体に入れる
    playerTexture->GetLevelDesc(0, &imageInfo);

    //画面サイズに合わせてスケーリングするための倍率を計算
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;

    playerMove.UpdatePosition();

    return SUCCEEDED(result);
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




