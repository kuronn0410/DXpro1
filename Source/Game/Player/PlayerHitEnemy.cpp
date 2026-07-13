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
	// プレーヤーが敵の座標に接触したかどうかを判定する処理をここに記述
	if (playerMove.player_x == enemy.centerX && playerMove.player_y == enemy.centerY)
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