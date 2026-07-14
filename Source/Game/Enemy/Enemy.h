#pragma once
#include "Graphics/dx2.h"
#include "Window/WindowState.h"
#include "Game/Collision/HitDetection.h"
#include "Game/Enemy/EnemyMove1.h"

class Enemy
{
public:
	bool Initialize();
	void Update();
	void Draw();
	void Finalize();
	const HitDetection& GetHitDetection() const;
	D3DSURFACE_DESC imageInfo = {};

	float scaleX = 0.0f;
	float scaleY = 0.0f;

private:
	EnemyMove1 enemyMove1;
	
	//テクスチャのアドレスを保持する変数
	IDirect3DTexture9* EnemyTexture = nullptr;
	//スプライトのアドレスを保持する変数
	ID3DXSprite* EnemySprite = nullptr;

	/*---------
	Draw関数で使用する変数
	-----------*/

	//HitDetection hitDetection{};

	//画像の中心座標を保持する変数
	// *範囲追加後いらないかも
	float centerX = 0.0f;
	float centerY = 0.0f;
};

