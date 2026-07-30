#include "Game/GameMain.h"

#include "Game/Turn/TurnEnd.h"
#include <string>

void GameMain::Initialize()
{
	// ゲームの初期化処理をここに記述
	playerManager.Init(characterManager.GetAllPartyCharacter());
	/*enemy.Initialize();*/
	turnFont.Init(g_device);
}

void GameMain::Update()
{
	/*turnManager.UpdateTurn(playerManager);*/
	switch (turnManager.GetTurnState())
	{
		case TurnState::TurnStart:
			if (TurnStartCheck())
			{
				turnManager.SetTurnState(TurnState::PlayerSelect);
			}
			break;
		case TurnState::PlayerSelect:
			turnManager.SetTurnState(TurnState::PlayerAction);
			break;
		case TurnState::PlayerAction:
			//playerActionManager.UpdateAction(playerManager);
			if (playerManager.Update())
			{
				turnManager.SetTurnState(TurnState::EnemyAction);
			}
			break;
		case TurnState::EnemyAction:
			//enemyActionManager.UpdateAction();
			turnManager.SetTurnState(TurnState::TurnEnd);
			break;
		case TurnState::TurnEnd:
			//turnManager.UpdateTurn(playerManager);
			currentTurn++;
			turnManager.SetTurnState(TurnState::TurnStart);
			break;
	}
	
}
void GameMain::Draw()
{
	// プレイヤーの描画処理を呼び出す
	playerManager.Draw();
	std::string turntext = "Turn: " + std::to_string(currentTurn);
	turnFont.Draw(turntext.c_str(), 10, 60); // ターン数を描画
	//turnFont.Draw("STAGE 1", 10, 60); // フォント描画の例
	//if (enemy.IsAlive)
	//{
	//	enemy.Draw();
	//}
	//else
	//{
	//	// 敵が倒された場合の処理をここに記述
	//}
	
}


void GameMain::Finalize()
{
	// ゲームの終了処理をここに記述
	playerManager.Finalize();
	/*enemy.Finalize();*/
}


bool GameMain::TurnStartCheck()
{

	return true;
}