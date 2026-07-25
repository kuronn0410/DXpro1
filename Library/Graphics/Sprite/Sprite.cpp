#include "Sprite.h"
namespace Library
{
    namespace Graphics
    {
        bool Sprite::Init(IDirect3DDevice9* g_device, const char* filePath)
        {
            HRESULT result = D3DXCreateSprite(
                g_device,//g_deviceが管理している描画環境を使って
                &sprite // 作ったSpriteのアドレスをEnemySpriteに入れてもらう
            );

            if (FAILED(result))
            {
                return false;
            }

            result = D3DXCreateTextureFromFile(
                g_device,//g_deviceが管理している描画環境を使って
                filePath,//読み込むPNG画像のパスを指定
                &texture//作ったTextureのアドレスをEnemyTextureに入れてもらう
            );

            if (FAILED(result))
            {
                sprite->Release();
                sprite = nullptr;
                texture = nullptr;
                return false;
            }

            texture->GetLevelDesc(0, &imageInfo);
            return SUCCEEDED(result);
        }

        void Sprite::Draw(float posX, float posY, float scaleX, float scaleY)
        {
            /*
            imageInfo構造体を用意する
            構造体に画像の情報を入れる


            //*/
            //アドレスが入っていない場合は描画処理を行わない
            if (sprite == nullptr ||
                texture == nullptr)
            {
                return;
            }

            //拡大率
            D3DXVECTOR2 scale(scaleX, scaleY);
            //敵の座標を構造体に入れる
            D3DXVECTOR2 position(posX, posY);
            //計算結果の保存先
            D3DXMATRIX Matrix;

            ////
            D3DXMatrixTransformation2D(
                &Matrix,//計算結果の保存先アドレスを指定
                nullptr,
                0.0f,
                &scale,
                nullptr,
                0.0f,
                &position
            );

            sprite->Begin(D3DXSPRITE_ALPHABLEND);
            sprite->SetTransform(&Matrix);

            sprite->Draw(
                texture,
                nullptr,
                nullptr,
                nullptr,
                D3DCOLOR_XRGB(255, 255, 255)
            );

            sprite->End();
        }

        void Sprite::Release()
        {
            if (texture != nullptr)
            {
                texture->Release();
                texture = nullptr;
            }

            if (sprite != nullptr)
            {
                sprite->Release();
                sprite = nullptr;
            }
        }

        const D3DSURFACE_DESC& Sprite::GetImageInfo() const
        {
            return imageInfo;
        }
    }
}