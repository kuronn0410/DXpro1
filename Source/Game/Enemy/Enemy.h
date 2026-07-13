#pragma once
#include "Graphics/dx2.h"
#include "Window/WindowState.h"

struct HitDetection
{
	float x;
	float y;
	float width;
	float height;
};

class Enemy
{
public:
	bool Initialize();
	void Update();
	void Draw();
	void Finalize();
	const HitDetection& GetHitDetection() const;

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

	HitDetection hitDetection{};

	//画像の中心座標を保持する変数
	// *範囲追加後いらないかも
	float centerX = 0.0f;
	float centerY = 0.0f;

	D3DSURFACE_DESC imageInfo = {};
};

