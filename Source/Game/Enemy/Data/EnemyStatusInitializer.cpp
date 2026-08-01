#include "Game/Enemy/Data/EnemyStatusInitializer.h"

bool EnemyStatusInitializer::Initialize()
{
	if (!enemyDatabase.Initialize())
	{
		return false;
	}

	if (!stageEnemyData.Initialize())
	{
		return false;
	}
	return true;
}

bool EnemyStatusInitializer::CreateEnemyStatuses(int stageNum)
{
	enemyStatuses.clear();
	const auto* stageEnemyMap = stageEnemyData.GetStageEnemyMap(stageNum);

	if (stageEnemyMap == nullptr)
	{
		return false;
	}

	for (const auto&  stagePair : *stageEnemyMap)
	{
		const StageEnemyEntry& entry = 
			stagePair.second;
		// 敵の基礎データを取得
		const EnemyData* enemyData = enemyDatabase.SearchEnemy(entry.type);

		if (enemyData == nullptr)
		{
			return false;
		}

		// 送る敵のステータスを作成
		EnemyStatus enemyStatus;

		enemyStatus.spritePath = enemyData->spritePath;
		enemyStatus.type = entry.type;
		enemyStatus.maxHp = enemyData->maxHp*(entry.hpMultiplier);
		enemyStatus.currentHp = enemyStatus.maxHp;
		enemyStatus.atk = enemyData->atk*(entry.atkMultiplier);
		enemyStatus.spd = enemyData->spd*(entry.spdMultiplier);

		for(const auto& pos : entry.positions)
		{
			enemyStatus.position = pos; // 最初のポジションを設定
			enemyStatuses.push_back(enemyStatus);
		}
	}
	return true;
}

const std::vector<EnemyStatus>& EnemyStatusInitializer::GetEnemyStatuses() const
{
	return enemyStatuses;
}