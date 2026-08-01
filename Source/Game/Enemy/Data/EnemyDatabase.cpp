#include "Game/Enemy/Data/EnemyDatabase.h"

bool EnemyDatabase::Initialize()
{
	
	CreateEnemyDatabase();
	return true;
}

const EnemyData* EnemyDatabase::SearchEnemy(EnemyType type) const
{
	for (const auto& enemy : enemyMap)
	{
		if (enemy.second.type == type)
		{
			return &enemy.second;
		}
	}
	return nullptr;
}

void EnemyDatabase::CreateEnemyDatabase()
{
	for (const auto& data : datas)
	{
		enemyMap[data.type] = data;
	}
}