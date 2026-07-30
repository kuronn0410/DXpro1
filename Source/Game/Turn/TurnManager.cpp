#include "Game/Turn/TurnManager.h"
//#include "Game/Turn/TurnEnd.h"
//#include "Game/Turn/TurnStart.h"


//int currentTurn = 0; // 現在のターンを管理する変数
// 現在のターン状態
//TurnState currentTurnState = TurnState::TurnStart;

// 現在の行動状態
//ActionState currentActionState = ActionState::None;
//void TurnManager::UpdateTurn(PlayerManager& playerManager)
//{
//	//switch (currentTurnState)
//	//{
//	//case TurnState::TurnStart:
//	//	TurnStart();
//	//	//currentActionState = ActionState::None;
//	//	break;
//	//case TurnState::PlayerSelect:
//	//	break;
//	//case TurnState::PlayerAction:
//	//	// プレイヤーの行動を更新
//	//	playerActionManager.UpdateAction(playerManager);
//	//	break;
//	//case TurnState::EnemyAction:
//	//	enemyActionManager.UpdateAction();
//	//	break;
//	//case TurnState::TurnEnd:
//	//	TurnEndCheck();
//	//	break;
//	//default:
//	//	break;
//	//}
//}


const TurnState& TurnManager::GetTurnState() const
{
	return currentTurnState;
}

// 状態変更
void TurnManager::SetTurnState(TurnState state)
{
	currentTurnState = state;
}
// 状態変更
