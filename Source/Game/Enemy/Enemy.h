#pragma once
#include "Graphics/dx2.h"
class Enemy
{
public:
	bool Initialize();
	void Update();
	void Draw();
	void Finalize();

	//画像の中心座標を保持する変数
	float centerX = 0.0f;
	float centerY = 0.0f;
	/*void OnLostDevice();
	void OnResetDevice();
	float GetScaleX() const;
	float GetScaleY() const;*/
private:
	//テクスチャのアドレスを保持する変数
	IDirect3DTexture9* EnemyTexture = nullptr;
	//スプライトのアドレスを保持する変数
	ID3DXSprite* EnemySprite = nullptr;

	/*---------
	Draw関数で使用する変数
	-----------*/

	//敵のX座標
	float Enemy_X = 10.0f;
	//敵のY座標
	float Enemy_Y = 10.0f;

	float scaleX = 0.0f;
	float scaleY = 0.0f;
	
	
};