#include "Game/Collision/CollisionManager.h"
#include "DebugTools/Debug.h"


void CollisionManager::Update(
	PlayerManager& playerManager,
	EnemyManager& enemyManager,
	TurnState turnState
)
{
	switch (turnState)
	{
	case TurnState::PlayerAction:
		PlayerTurnCollision(playerManager, enemyManager);
			break;
	case TurnState::EnemyAction:
		EnemyTurnCollision(playerManager, enemyManager);
		break;
	default:
		return;
	}
}

void CollisionManager::PlayerTurnCollision(PlayerManager& playerManager, EnemyManager& enemyManager)
{
	int playerCount = playerManager.GetPlayerCount();
	int enemyCount = enemyManager.GetEnemyCount();
	for(int i = 0; i < playerCount; i++)
	{
		for(int j = 0; j < enemyCount; j++)
		{
			// プレイヤーの当たり判定を取得
			const auto& playerHitDetection = playerManager.GetHitDetection(i);
			// 敵の当たり判定を取得
			const auto& enemiesHitDetection = enemyManager.GetHitDetection(j);
			if(IsHit(playerHitDetection, enemiesHitDetection))
			{
				enemyManager.TakeDamage(j, playerManager.GetAttack(i));
				Library::DebugTools::DebugLog("HIT");
			}
		}
	}
}

void CollisionManager::EnemyTurnCollision(PlayerManager& playerManager, EnemyManager& enemyManager)
{
	int playerCount = playerManager.GetPlayerCount();
	int enemyCount = enemyManager.GetEnemyCount();
	for(int i = 0; i < playerCount; i++)
	{
		for(int j = 0; j < enemyCount; j++)
		{
			// プレイヤーの当たり判定を取得
			const auto& playerHitDetection = playerManager.GetHitDetection(i);
			// 敵の当たり判定を取得
			const auto& enemiesHitDetection = enemyManager.GetHitDetection(j);
			if(IsHit(enemiesHitDetection,playerHitDetection))
			{
				playerManager.TakeDamage(i, enemyManager.GetAttack(j));
				Library::DebugTools::DebugLog("HIT");
			}
		}
	}
}