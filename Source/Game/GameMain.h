#pragma once
#include "Game/Player/PlayerManager.h"	
#include "Game/Turn/TurnManager.h"
#include "Game/Enemy/EnemyManager.h"
#include "Graphics/Font/Font.h"
#include "Party/CharacterStatus.h"
#include "Party/CharacterManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/PlayerActionManager.h"
#include "Game/Turn/TurnEnd.h"
#include "Game/Turn/TurnStart.h"


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
private:
	Font turnFont;
	TurnManager turnManager;
	PlayerManager playerManager;
	EnemyManager enemyManager;
	/*Enemy enemy;*/
	/*EnemyActionManager enemyActionManager;*/
	/*PlayerActionManager playerActionManager;*/
	CharacterManager& characterManager;

	/*EnemyStatusInitializer& enemyStatusInitializer;*/
	EnemyStatusInitializer& enemyStatusInitializer;
	bool TurnStartCheck();
	int currentTurn = 1; // 現在のターン数を管理する変数
	int moveIndex = 0; // 動かすキャラクターのインデックスを管理する変数
	int stageNum = 1; // 挑むステージの番号を管理する変数
};