#include "Game/Enemy/Data/StageEnemyData.h"

bool StageEnemyData::Initialize()
{
	CreateStageEnemyData();
	return true;
}


const std::unordered_map<int, StageEnemyEntry>* StageEnemyData::GetStageEnemyMap(int stage) const
{
	switch (stage)
	{
	case 1:
		return &stage1EnemyMap;
	case 2:
		return &stage2EnemyMap;
	default:
		return nullptr;
		break;
	}	
}

void StageEnemyData::CreateStageEnemyData()
{
	
	for (int i = 0; i < 3; ++i)
	{
		stage1EnemyMap[i] = stage1EnemyData[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		stage2EnemyMap[i] = stage2EnemyData[i];
	}
}