#include "Game/Enemy/EnemyManager.h"

bool EnemyManager::Initialize(std::vector<EnemyStatus> statuses)
{
	enemyStatuses = statuses;
	for(auto& status : enemyStatuses)
	{
		Enemy enemy;
		enemy.Initialize(status);
		enemies.push_back(enemy);
	}
	
	return true;	
}

bool EnemyManager::Update()
{
	for(auto& enemy : enemies)
	{
		enemy.Update();
	}
	return true;
}

void EnemyManager::Draw()
{
	for (auto& enemy : enemies)
	{
		enemy.Draw();
	}
}

void EnemyManager::Finalize()
{
	for (auto& enemy : enemies)
	{
		enemy.Finalize();
	}
}


