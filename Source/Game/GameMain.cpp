#include "Game/GameMain.h"
#include "Game/Player/Player.h"	
#include "Game/Turn/TurnManager.h"
#include "Game/Enemy/Enemy.h"
#include "Graphics/Font/Font.h"
#include "Game/Turn/TurnEnd.h"
#include <string>


/*
ゲームのメイン処理
ターンの進行やプレイヤーの更新、描画などを管理する
*/
TurnManager turnManager; // ターン管理オブジェクトのインスタンス
extern Player player; // プレイヤーオブジェクトのインスタンス
extern Enemy enemy; // 敵オブジェクトのインスタンス
Font turnFont; // フォントオブジェクトのインスタンス
void GameInitialize()
{
	// ゲームの初期化処理をここに記述
	player.Initialize();
	enemy.Initialize();
	turnFont.Init(g_device);


}

void GameUpdate()
{
	turnManager.UpdateTurn();
	
}
void GameDraw()
{
	// プレイヤーの描画処理を呼び出す
	player.Draw();
	std::string turntext = "Turn: " + std::to_string(turnManager.currentTurn);
	turnFont.Draw(turntext.c_str(), 10, 60); // ターン数を描画
	//turnFont.Draw("STAGE 1", 10, 60); // フォント描画の例
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