//#include "Game/Player/PlayerHitEnemy.h"
//#include "Game/Player/Player.h"
//#include "Game/Player/PlayerDealDamage.h"
//#include "Game/Enemy/Enemy.h"
////当たり判定
//#include "Game/Collision/HitDetection.h"
//#include "Game/Collision/Collision.h"
//
//#include <Windows.h>
//#include <cstdio>
////extern PlayerMove playerMove;
//extern Enemy enemy;
//PlayerDealDamage playerDealDamage;
//extern Player player;
//void PlayerHitEnemy::Update()
//{
//	HitEnemy();
//
//}
//
//void PlayerHitEnemy::HitEnemy()
//{
//	const HitDetection& enemyHit = enemy.GetHitDetection();
//	const HitDetection& playerHit = player.GetHitDetection();
//	// プレーヤーが敵の座標に接触したかどうかを判定する処理をここに記述
//	if (IsHit(enemyHit, playerHit) && !isDamage)
//	{
//		int damage = playerDealDamage.PlayerDealDamages();
//		enemy.DamageToCharacter(damage);
//		isDamage = true;
//
//
//		char buffer[128];
//		sprintf_s(
//			buffer,
//			sizeof(buffer),
//			"Damage = %d\n",
//			damage
//		);
//		OutputDebugStringA(buffer);
//	}
//	return;
//}