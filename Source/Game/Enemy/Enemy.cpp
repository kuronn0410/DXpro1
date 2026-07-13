#include "Game/Enemy/Enemy.h"

bool Enemy::Initialize()
{
	/*
	スプライト作成
	テクスチャ作成
	FAILED
	SUCCEEDED
	*/
	HRESULT result = D3DXCreateSprite(
		g_device,//g_deviceが管理している描画環境を使って
		&EnemySprite // 作ったSpriteのアドレスをEnemySpriteに入れてもらう
	);

	if (FAILED(result))
	{
		return false;
	}

	result = D3DXCreateTextureFromFile(

		g_device,//g_deviceが管理している描画環境を使って
		"Assets\\Textures\\Goal.png",//読み込むPNG画像のパスを指定
		&EnemyTexture//作ったTextureのアドレスをEnemyTextureに入れてもらう
	);

	if (FAILED(result))
	{
		EnemySprite->Release();
		EnemySprite = nullptr;
		EnemyTexture = nullptr;
		return false;
	}
	return SUCCEEDED(result);
}

void Enemy::Update()
{
	return;
	// 敵の更新処理をここに記述
}


void Enemy::Finalize()
{
	// 敵の終了処理をここに記述
	if (EnemyTexture)
	{
		EnemyTexture->Release();
		EnemyTexture = nullptr;
	}
	if (EnemySprite)
	{
		EnemySprite->Release();
		EnemySprite = nullptr;
	}
}