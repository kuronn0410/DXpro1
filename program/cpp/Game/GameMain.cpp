#include "header/Game/GameMain.h"
#include "header/Game/Player.h"	
#include "header/Game/PlayerMove.h"


void GameInitialize()
{
	// ゲームの初期化処理をここに記述
	player_initialize();
}

void GameUpdate()
{
	//プレーヤーの更新処理を呼び出す
	player_move();

}
void GameDraw()
{
	// プレイヤーの描画処理を呼び出す
	player_draw();
}


void GameFinalize()
{
	// ゲームの終了処理をここに記述
	player_finalize();
}