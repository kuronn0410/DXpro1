#pragma once
#include "Game/Enemy/Enemy.h"
#include "Game/Enemy/Data/EnemyStatus.h"
#include <vector>

class EnemyManager
{
public:
	bool Initialize(const std::vector<EnemyStatus>& statuses);
	bool Update();
	void Draw();
	void Finalize();

	/*-----取得、指示の受付-----*/
	void StartTurn();
	const HitDetection& GetHitDetection(int Index) const;
	const int GetEnemyCount() const;// 敵の数を取得する関数
	void TakeDamage(int Index,int damage); // 指定した敵の攻撃力を取得する関数
	bool GetEnemyAnnihilation() const;
private:

	//実体の敵キャラクターを保持するベクター
	std::vector<Enemy> enemies;
	//ステージで使う敵キャラのステータスを保持するベクター
	std::vector<EnemyStatus> enemyStatuses; // 敵のステータスを保持するベクター

	/*-----取得、指示の受付-----*/
	bool isAnnihilation = false; // 敵が全滅したかどうかを判断するフラグ
};
