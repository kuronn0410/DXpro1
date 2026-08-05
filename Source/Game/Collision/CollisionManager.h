#pragma once
#include "Game/Player/PlayerManager.h"
#include "Game/Enemy/EnemyManager.h"
#include "Game/Collision/Collision.h"
#include "Game/Turn/TurnManager.h"
	
class CollisionManager
{
public:
	void Update(
		PlayerManager& playerManager, 
		EnemyManager& enemyManager,
		TurnState turnState
	);

	
private:
	void PlayerTurnCollision(PlayerManager& playerManager, EnemyManager& enemyManager);
	void EnemyTurnCollision(PlayerManager& playerManager, EnemyManager& enemyManager);
};