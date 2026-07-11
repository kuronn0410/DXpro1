#include "Game/GameMain.h"
#include "Game/Player/Player.h"	
#include "Game/Player/PlayerMove.h"

Player player; // プレイヤーオブジェクトのインスタンス

void GameInitialize()
{
	// ゲームの初期化処理をここに記述
	player.Initialize();
}

void GameUpdate()
{
	//プレーヤーの更新処理を呼び出す
	player.Update();

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