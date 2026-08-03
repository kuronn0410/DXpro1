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
	void StartTurn();
	const HitDetection& GetHitDetection(int Index) const;
	const int GetEnemyCount() const;// 敵の数を取得する関数
private:

	//実体の敵キャラクターを保持するベクター
	std::vector<Enemy> enemies;

	//ステージで使う敵キャラのステータスを保持するベクター
	std::vector<EnemyStatus> enemyStatuses; // 敵のステータスを保持するベクター
};
