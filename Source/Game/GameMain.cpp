#include "Game/GameMain.h"
#include "Game/Player/Player.h"	
#include "Game/Player/PlayerMove.h"
#include "Game/Turn/TurnManager.h"
#include "Game/Enemy/Enemy.h"


/*
ゲームのメイン処理
ターンの進行やプレイヤーの更新、描画などを管理する
*/
TurnManager turnManager; // ターン管理オブジェクトのインスタンス
extern Player player; // プレイヤーオブジェクトのインスタンス
extern Enemy enemy; // 敵オブジェクトのインスタンス

void GameInitialize()
{
	// ゲームの初期化処理をここに記述
	player.Initialize();
	enemy.Initialize();
}

void GameUpdate()
{
	turnManager.UpdateTurn();
	
}
void GameDraw()
{
	// プレイヤーの描画処理を呼び出す
	player.Draw();
	if (enemy.IsAlive)
	{
		enemy.Draw();
	}
	else
	{
		// 敵が倒された場合の処理をここに記述
	}
}


void GameFinalize()
{
	// ゲームの終了処理をここに記述
	player.Finalize();
	enemy.Finalize();
}