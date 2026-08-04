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
			// ƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è‚ðŽæ“¾
			const auto& playerHitDetection = playerManager.GetHitDetection(i);
			// “G‚Ì“–‚½‚è”»’è‚ðŽæ“¾
			const auto& enemiesHitDetection = enemyManager.GetHitDetection(j);

			if(IsHit(playerHitDetection, enemiesHitDetection))
			{
				enemyManager.TakeDamage(j, playerManager.GetAttack(i));

				Library::DebugTools::DebugLog("HIT");
			}
		}
	}
}