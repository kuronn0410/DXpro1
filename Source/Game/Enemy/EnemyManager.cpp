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
		if(!enemy.Update())
		{
			return false;
		}
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

/*-----æ“¾Aw¦‚Ìó•t-----*/
void EnemyManager::StartTurn()
{
	for (auto& enemy : enemies)
	{
		enemy.StartTurn();
	}
}

const HitDetection& EnemyManager::GetHitDetection(int Index) const
{
	return enemies[Index].GetHitDetection();
}

const int EnemyManager::GetEnemyCount() const
{
	return static_cast<int>(enemies.size());
}