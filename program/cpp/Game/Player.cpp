#include "header/Game/Player.h"
#include "header\Graphics\dx2.h"
#include "header/WindowState.h"
#include "header/Game/PlayerMove.h"


static IDirect3DTexture9* playerTexture = nullptr;
static ID3DXSprite* playerSprite = nullptr;
float scaleX = 0.0f;
float scaleY = 0.0f;
float centerX = 0.0f;
float centerY = 0.0f;


bool player_initialize()
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
}



void player_draw()
{
	// プレイヤーの描画処理をここに記述
    // 背景の描画処理をここに記述
    if (playerSprite == nullptr ||
        playerTexture == nullptr)
    {
        return;
    }

    D3DSURFACE_DESC imageInfo = {};
    playerTexture->GetLevelDesc(0, &imageInfo);

	//画面サイズに合わせてスケーリングするための倍率を計算
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width)*0.25f;

    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height)* 0.25f;
    

	D3DXVECTOR2 scale(scaleX, scaleY);
    D3DXVECTOR2 position(player_x, player_y);
    D3DXMATRIX Matrix;
    
    D3DXMatrixTransformation2D(
        &Matrix,
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

void player_finalize()
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

void PlayerOnLostDevice()
{
    if (playerSprite != nullptr)
    {
        playerSprite->OnLostDevice();
    }
}

void PlayerOnResetDevice()
{
    if (playerSprite != nullptr)
    {
        playerSprite->OnResetDevice();
    }
}