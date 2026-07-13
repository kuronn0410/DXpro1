#include "Game/Player/Player.h"
#include "Window/WindowState.h"
#include "Game/Player/PlayerMove.h"


extern PlayerMove playerMove;

void Player::Draw()
{
    // プレイヤーの描画処理をここに記述
    // 背景の描画処理をここに記述
    if (playerSprite == nullptr ||
        playerTexture == nullptr)
    {
        return;
    }
    //構造体の用意
    D3DSURFACE_DESC imageInfo = {};

	//playerTextureが示してる画像の情報を取得して構造体に入れる
    playerTexture->GetLevelDesc(0, &imageInfo);

    //画面サイズに合わせてスケーリングするための倍率を計算
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;


    //拡大率
    D3DXVECTOR2 scale(scaleX, scaleY);
	//プレイヤーの座標を構造体に入れる
    D3DXVECTOR2 position(playerMove.player_x, playerMove.player_y);
    //計算結果の保存先
    D3DXMATRIX Matrix;

    //
    D3DXMatrixTransformation2D(
		&Matrix,//計算結果の保存先アドレスを指定
        nullptr,
        0.0f,
        &scale,
        nullptr,
        0.0f,
        &position
    );

    centerX = position.x + imageInfo.Width * scale.x * 0.5f;
    centerY = position.y + imageInfo.Height * scale.y * 0.5f;

    playerSprite->Begin(D3DXSPRITE_ALPHABLEND);
    playerSprite->SetTransform(&Matrix);

    playerSprite->Draw(
        playerTexture,
        nullptr,
        nullptr,
        nullptr,
        D3DCOLOR_XRGB(255, 255, 255)
    );

    playerSprite->End();
}