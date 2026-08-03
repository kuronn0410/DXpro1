#pragma once
#include "Game/Player/PlayerManager.h"
#include "Game/Enemy/EnemyManager.h"
#include "Game/Collision/Collision.h"

	
class CollisionManager
{
public:
	void Update(
		PlayerManager& playerManager, 
		EnemyManager& enemyManager
	);
private:

};