#include "Game/Player/PlayerHitEnemy.h"
#include "Game/Player/PlayerMove.h"
#include "Game/Player/PlayerDealDamage.h"
#include "Game/Enemy/Enemy.h"

#include <Windows.h>
#include <cstdio>
extern PlayerMove playerMove;
extern Enemy enemy;
PlayerDealDamage playerDealDamage;
void PlayerHitEnemy::Update()
{
	HitEnemy();

}

void PlayerHitEnemy::HitEnemy()
{
	const HitDetection& enemyHit = enemy.GetHitDetection();
	// プレーヤーが敵の座標に接触したかどうかを判定する処理をここに記述
	if (enemyHit.x < playerMove.player_x && playerMove.player_x < enemyHit.x + enemyHit.width &&
		enemyHit.y < playerMove.player_y && playerMove.player_y < enemyHit.y + enemyHit.height)
	{
		int damage = playerDealDamage.PlayerDealDamages();
		char buffer[128];
		sprintf_s(
			buffer,
			sizeof(buffer),
			"Damage = %d\n",
			damage
		);
		OutputDebugStringA(buffer);
	}


	return;
}