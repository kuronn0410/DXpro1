#include "Game/Enemy/Enemy.h"
#include "Window/WindowState.h"


void Enemy::Draw()
{
    /*
	imageInfo構造体を用意する
	構造体に画像の情報を入れる


    */

	//アドレスが入っていない場合は描画処理を行わない
    if (EnemySprite == nullptr ||
        EnemyTexture == nullptr)
    {
        return;
    }

    //initに移す
    D3DSURFACE_DESC imageInfo = {};
    EnemyTexture->GetLevelDesc(0, &imageInfo);


    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;

    //拡大率
    D3DXVECTOR2 scale(scaleX, scaleY);
    //敵の座標を構造体に入れる
    D3DXVECTOR2 position(Enemy_X, Enemy_Y);
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

    EnemySprite->Begin(D3DXSPRITE_ALPHABLEND);
    EnemySprite->SetTransform(&Matrix);

    EnemySprite->Draw(
        EnemyTexture,
        nullptr,
        nullptr,
        nullptr,
        D3DCOLOR_XRGB(255, 255, 255)
    );

    EnemySprite->End();
}