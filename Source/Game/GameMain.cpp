#include "Game/GameMain.h"
#include "Game/Player/Player.h"	
#include "Game/Player/PlayerMove.h"
#include "Game/Turn/TurnManager.h"


/*
ゲームのメイン処理
ターンの進行やプレイヤーの更新、描画などを管理する
*/

Player player; // プレイヤーオブジェクトのインスタンス

void GameInitialize()
{
	// ゲームの初期化処理をここに記述
	player.Initialize();
}

void GameUpdate()
{
	UpdateTurn();
	//プレーヤーの更新処理を呼び出す
	if (currentTurnState == TurnState::PlayerAction &&
		currentActionState == ActionState::Move)
	{
		player.Update();
	}

}
void GameDraw()
{
	// プレイヤーの描画処理を呼び出す
	player.Draw();
}


void GameFinalize()
{
	// ゲームの終了処理をここに記述
	player.Finalize();
}