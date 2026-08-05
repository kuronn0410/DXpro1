#pragma once
#include "Game/Player/PlayerManager.h"	
#include "Game/Turn/TurnManager.h"
#include "Game/Enemy/EnemyManager.h"
#include "Graphics/Font/Font.h"
#include "Party/CharacterStatus.h"
#include "Party/CharacterManager.h"
#include "Game/Collision/CollisionManager.h"


//たぶんいらない
#include "Game/Enemy/Data/EnemyStatusInitializer.h"

class GameMain
{
public:
	explicit GameMain(
		CharacterManager& manager, 
		EnemyStatusInitializer& enemyStatusInitializer) : 
		characterManager(manager), 
		enemyStatusInitializer(enemyStatusInitializer) {};
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
	/*---取得---*/
	/*---指示の受付---*/
	const bool GameFinished() const;

private:
	Font turnFont;
	TurnManager turnManager;
	PlayerManager playerManager;
	EnemyManager enemyManager;
	CharacterManager& characterManager;
	EnemyStatusInitializer& enemyStatusInitializer;
	CollisionManager collisionManager;
	bool TurnStartCheck();
	int currentTurn = 1; // 現在のターン数を管理する変数
	int moveIndex = 0; // 動かすキャラクターのインデックスを管理する変数
	int stageNum = 1; // 挑むステージの番号を管理する変数
	bool isGameFinished = false; // ゲームが終了したかどうかを判断するフラグ
};
