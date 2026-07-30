#pragma once
#include "Game/Player/PlayerManager.h"	
#include "Game/Turn/TurnManager.h"
#include "Game/Enemy/Enemy.h"
#include "Graphics/Font/Font.h"
#include "Party/CharacterStatus.h"
#include "Party/CharacterManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/PlayerActionManager.h"
#include "Game/Turn/TurnEnd.h"
#include "Game/Turn/TurnStart.h"
class GameMain
{
public:
	explicit GameMain(CharacterManager& manager) : characterManager(manager) {};
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
private:
	Font turnFont;
	TurnManager turnManager;
	PlayerManager playerManager;
	//EnemyManager enemyManager;‚É•Ï‚¦‚é
	/*Enemy enemy;*/
	EnemyActionManager enemyActionManager;
	PlayerActionManager playerActionManager;
	CharacterManager& characterManager;

	bool TurnStartCheck();
	int currentTurn = 1; // Œ»İ‚Ìƒ^[ƒ“”‚ğŠÇ—‚·‚é•Ï”
};