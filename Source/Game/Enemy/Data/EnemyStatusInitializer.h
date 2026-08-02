#pragma once
#include "Game/Enemy/Data/EnemyStatus.h"
#include "Game/StartPos.h"
#include "Game/Enemy/EnemyType.h"
#include "Game/Enemy/Data/EnemyDatabase.h"
#include "Game/Enemy/Data/StageEnemyData.h"
#include "Game/Enemy/Data/EnemyData.h"
#include <vector>


class EnemyStatusInitializer
{
public:
	bool Initialize();
	bool CreateEnemyStatuses(/*int stageNum*/);	
	const std::vector<EnemyStatus>& GetEnemyStatuses() const;
	void SetStageNum(int stage);
private:
	//ゲーム側に渡す敵のステータスリスト
	std::vector<EnemyStatus> enemyStatuses;

	/*---実体---*/
	EnemyDatabase enemyDatabase;
	StageEnemyData stageEnemyData;
	int stageNum = 1; // 挑むステージの番号を管理する変数
};