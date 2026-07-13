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


	//initに移す
	
	EnemyTexture->GetLevelDesc(0, &imageInfo);
	scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
	scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;
	// 敵の当たり判定の初期化
	hitDetection.x = Enemy_X;
	hitDetection.y = Enemy_Y;
	hitDetection.width = static_cast<float>(imageInfo.Width) * scaleX;
	hitDetection.height = static_cast<float>(imageInfo.Height) * scaleY;

	

	
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


const HitDetection& Enemy::GetHitDetection() const
{
	return hitDetection;
}