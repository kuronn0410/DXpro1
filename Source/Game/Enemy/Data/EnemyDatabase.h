#pragma once

#include "Game/Enemy/Data/EnemyData.h"
#include <unordered_map>

class EnemyDatabase
{
public:
	bool Initialize();
	const EnemyData* SearchEnemy(EnemyType type) const;
	void CreateEnemyDatabase();

private:
	std::unordered_map<EnemyType, EnemyData> enemyMap;
	EnemyData datas[3] = {
		{ EnemyType::VoidKnight, "Assets/Textures/Enemy/VoidKnight.png", 200, 30, 10 },
		{ EnemyType::JadeDrake, "Assets/Textures/Enemy/JadeDrake.png", 150, 25, 15 },
		{ EnemyType::Scavenger, "Assets/Textures/Enemy/Scavenger.png", 100, 20, 20 }
	};
};