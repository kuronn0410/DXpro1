#pragma once
#include "Game/Enemy/Enemy.h"
#include "Game/Enemy/Data/EnemyStatus.h"
#include <vector>

class EnemyManager
{
public:
	bool Initialize(std::vector<EnemyStatus> statuses);
	bool Update();
	void Draw();
	void Finalize();

	/*-----取得、指示の受付-----*/

private:

	//実体の敵キャラクターを保持するベクター
	std::vector<Enemy> enemies;

	//ステージで使う敵キャラのステータスを保持するベクター
	std::vector<EnemyStatus> enemyStatuses; // 敵のステータスを保持するベクター
};
