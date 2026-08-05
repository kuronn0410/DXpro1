#include "Game/GameMain.h"

//#include "Game/Turn/TurnEnd.h"
#include <string>
#include "DebugTools/Debug.h"

void GameMain::Initialize(/*int stageNum*/)
{
	/*--プレーヤー*/
	bool result = playerManager.Init(characterManager.GetAllPartyCharacter(), characterManager.GetPartyCount());
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
		{
			if (TurnStartCheck())
			{
				turnManager.SetTurnState(TurnState::PlayerSelect);
			}
			break;
		}
		case TurnState::PlayerSelect:
		{
			playerManager.PlayerSelectTurn(moveIndex);
			if (moveIndex < playerManager.GetPlayerCount() - 1)
			{
				moveIndex++;
			}
			else
			{
				moveIndex = 0;
			}
			turnManager.SetTurnState(TurnState::PlayerAction);
			break;
		}
		case TurnState::PlayerAction:
		{
			//playerActionManager.UpdateAction(playerManager);

			const bool isMoving =
				playerManager.Update();

			collisionManager.Update(playerManager, enemyManager, turnManager.GetTurnState());

			if (!isMoving)
			{
				turnManager.SetTurnState(TurnState::EnemyAction);
			}
			if (playerManager.GetAnnihilation())
			{
				isGameFinished = true;
			}

			break;
		}
		case TurnState::EnemyAction:
		{
			bool isEnemyMoving = enemyManager.Update();

			collisionManager.Update(playerManager, enemyManager, turnManager.GetTurnState());

			if (!isEnemyMoving || enemyManager.GetEnemyAnnihilation())
			{
				turnManager.SetTurnState(TurnState::TurnEnd);
			}

			break;
		}
		case TurnState::TurnEnd:
		{
			//turnManager.UpdateTurn(playerManager);
			if (enemyManager.GetEnemyAnnihilation())
			{

				// 敵が全滅した場合の処理をここに記述
				Library::DebugTools::DebugLog("All enemies defeated!");
				isGameFinished = true; // ゲーム終了フラグを立てる
			}
			currentTurn++;
			turnManager.SetTurnState(TurnState::TurnStart);
			break;
		}
	}
	
}
void GameMain::Draw()
{
	// プレイヤーの描画処理を呼び出す
	enemyManager.Draw();
	playerManager.Draw();
	std::string turntext = "Turn: " + std::to_string(currentTurn);
	turnFont.Draw(turntext.c_str(), 10, 60); // ターン数を描画
	
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

const bool GameMain::GameFinished() const
{
	return isGameFinished;
}