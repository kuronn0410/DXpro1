#pragma once
#include "Game/Enemy/Data/EnemyStatus.h"
#include "Game/Enemy/EnemyMove1.h"
#include "Window/WindowState.h"
#include "Graphics/dx2.h"
//#include "Game/Collision/HitDetection.h"
//#include "Game/Enemy/EnemyMove1.h"
#include "Graphics/Sprite/Sprite.h"
//#include "Party/CharacterStatus.h"
//
//class Enemy
//{
//public:
//	bool Initialize();
//	void Update();
//	void Draw();
//	void Finalize();
//	const HitDetection& GetHitDetection() const;
//	D3DSURFACE_DESC imageInfo = {};
//
//	float scaleX = 0.0f;
//	float scaleY = 0.0f;
//	void DamageToCharacter(int damage);
//	bool IsAlive = true;
//private:
//
//	Library::Graphics::Sprite sprite;
//	EnemyMove1 enemyMove1;
//	
//	/*---------
//	Draw関数で使用する変数
//	-----------*/
//
//	//HitDetection hitDetection{};
//
//	////画像の中心座標を保持する変数
//	//// *範囲追加後いらないかも
//	//float centerX = 0.0f;
//	//float centerY = 0.0f;
//
//	CharacterStatus enemyStatus{};
//};
//

class Enemy
{
public:
	bool Initialize(EnemyStatus enemyStatus);
	bool Update();
	void Draw();
	void Finalize();
	/*-----取得、指示の受付-----*/
	bool GetIsAlive() const;

private:

	
	//Enemyの実体
	EnemyStatus enemyStatus{};
	Library::Graphics::Sprite sprite;
	D3DSURFACE_DESC imageInfo = {};

	EnemyMove1 enemyMove1;
	float Enemy_x = 0.0f;
	float Enemy_y = 0.0f;
	float scaleX = 0.0f;
	float scaleY = 0.0f;
	float imageWidth = 0.0f;
	float imageHeight = 0.0f;

	/*-----取得、指示の受付-----*/
	bool IsAlive = true; // 敵が生きているかどうかを判断するフラグ
};
