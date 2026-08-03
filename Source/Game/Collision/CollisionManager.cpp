#include "Game/Collision/CollisionManager.h"
#include "DebugTools/Debug.h"

void CollisionManager::Update(
	PlayerManager& playerManager, 
	EnemyManager& enemyManager
)
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
				//// 衝突が発生した場合の処理
				//playerManager.HandleCollisionWithEnemy(enemyManager, i, j);
				//enemyManager.HandleCollisionWithPlayer(playerManager, j, i);
				Library::DebugTools::DebugLog("HIT");
			}
		}
	}

	// プレイヤーと敵の衝突判定
	//for (const auto& enemy : enemies)
	//{
	//	const auto& enemyHitDetection = enemy.GetHitDetection();
	//	if (playerHitDetection.Intersects(enemyHitDetection))
	//	{
	//		// 衝突が発生した場合の処理
	//		playerManager.HandleCollisionWithEnemy(enemy);
	//		enemy.HandleCollisionWithPlayer(playerManager);
	//	}
	//}
}