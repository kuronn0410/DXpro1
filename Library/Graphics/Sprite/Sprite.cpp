#include "Sprite.h"
//DirectX9のヘッダーファイルをインクルード
#include <d3dx9.h>
#include "Graphics/dx2.h"


void Sprite::Init()
{
    ///*
    //スプライト作成
    //テクスチャ作成
    //FAILED
    //SUCCEEDED
    //*/
    //HRESULT result = D3DXCreateSprite(
    //    g_device,//g_deviceが管理している描画環境を使って
    //    &EnemySprite // 作ったSpriteのアドレスをEnemySpriteに入れてもらう
    //);

    //if (FAILED(result))
    //{
    //    return false;
    //}

    //result = D3DXCreateTextureFromFile(
    //    g_device,//g_deviceが管理している描画環境を使って
    //    "Assets\\Textures\\Goal.png",//読み込むPNG画像のパスを指定
    //    &EnemyTexture//作ったTextureのアドレスをEnemyTextureに入れてもらう
    //);

    //if (FAILED(result))
    //{
    //    EnemySprite->Release();
    //    EnemySprite = nullptr;
    //    EnemyTexture = nullptr;
    //    return false;
    //}


    //enemyMove1.Enemy_X = GameConfig::EnemyStartX;
    //enemyMove1.Enemy_Y = GameConfig::EnemyStartY;
    ////initに移す

    //EnemyTexture->GetLevelDesc(0, &imageInfo);
    //scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    //scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;
    //// 敵の当たり判定の初期化
    //enemyMove1.UpdatePosition();
    //return SUCCEEDED(result);
}

void Sprite::Draw()
{
    /*
    imageInfo構造体を用意する
    構造体に画像の情報を入れる


    //*/
    ////アドレスが入っていない場合は描画処理を行わない
    //if (EnemySprite == nullptr ||
    //    EnemyTexture == nullptr)
    //{
    //    return;
    //}
    //scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    //scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;

    ////拡大率
    //D3DXVECTOR2 scale(scaleX, scaleY);
    ////敵の座標を構造体に入れる
    //D3DXVECTOR2 position(enemyMove1.Enemy_X, enemyMove1.Enemy_Y);
    ////計算結果の保存先
    //D3DXMATRIX Matrix;

    ////
    //D3DXMatrixTransformation2D(
    //    &Matrix,//計算結果の保存先アドレスを指定
    //    nullptr,
    //    0.0f,
    //    &scale,
    //    nullptr,
    //    0.0f,
    //    &position
    //);


    //centerX = position.x + imageInfo.Width * scale.x * 0.5f;
    //centerY = position.y + imageInfo.Height * scale.y * 0.5f;

    //EnemySprite->Begin(D3DXSPRITE_ALPHABLEND);
    //EnemySprite->SetTransform(&Matrix);

    //EnemySprite->Draw(
    //    EnemyTexture,
    //    nullptr,
    //    nullptr,
    //    nullptr,
    //    D3DCOLOR_XRGB(255, 255, 255)
    //);

    ////EnemySprite->End();
}