#include "Game/Enemy/EnemyManager.h"
#include <algorithm>

bool EnemyManager::Initialize(const std::vector<EnemyStatus>& statuses)
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
	for (auto it = enemies.begin();
		it != enemies.end();)
	{
		if (!it->GetIsAlive())
		{
			it = enemies.erase(it);
			if(enemies.size() == 0)
			{
				isAnnihilation = true;
			}
			continue;
		}

		if (!it->Update())
		{
			return false;
		}

		++it;
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

void EnemyManager::TakeDamage(int Index,int damage) 
{
	enemies[Index].TakeDamage(damage);
}


bool EnemyManager::GetEnemyAnnihilation() const
{
	return isAnnihilation;
}