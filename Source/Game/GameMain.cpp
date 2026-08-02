#include "Game/GameMain.h"

//#include "Game/Turn/TurnEnd.h"
#include <string>
#include "DebugTools/Debug.h"

void GameMain::Initialize(/*int stageNum*/)
{
	/*--プレーヤー*/
	bool result = playerManager.Init(characterManager.GetAllPartyCharacter());
	if (!result)
	{
		Library::DebugTools::DebugLog("PlayerManager Initialize Failed");
	}
	/*--敵--*/ 
	enemyManager.Initialize(enemyStatusInitializer.GetEnemyStatuses());
	/*--その他--*/
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
			playerManager.PlayerSelectTurn(moveIndex);
			if(moveIndex < 3)
			{
				moveIndex++;
			}
			else
			{
				moveIndex = 0;
			}
			turnManager.SetTurnState(TurnState::PlayerAction);
			break;
		case TurnState::PlayerAction:
			//playerActionManager.UpdateAction(playerManager);
			if (!playerManager.Update())
			{
				turnManager.SetTurnState(TurnState::EnemyAction);
			}
			break;
		case TurnState::EnemyAction:		
			if (!enemyManager.Update())
			{
				turnManager.SetTurnState(TurnState::TurnEnd);
			}
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
	enemyManager.Draw();
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
	enemyManager.Finalize();
}


bool GameMain::TurnStartCheck()
{
	playerManager.StartTurn();
	enemyManager.StartTurn();
	return true;
}