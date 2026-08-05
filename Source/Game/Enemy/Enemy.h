#pragma once
#include "Game/Enemy/Data/EnemyStatus.h"
#include "Game/Enemy/EnemyMove1.h"
#include "Window/WindowState.h"
#include "Graphics/dx2.h"
#include "Graphics/Sprite/Sprite.h"

class Enemy
{
public:
	bool Initialize(EnemyStatus enemyStatus);
	bool Update();
	void Draw();
	void Finalize();
	/*-----取得-----*/
	bool GetIsAlive() const;
	const HitDetection& GetHitDetection() const;
	int GetAttack() const;
	/*-----指示の受付-----*/ 
	void TakeDamage(int damage);
	void StartTurn();

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
