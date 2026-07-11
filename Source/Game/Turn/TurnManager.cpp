#include "Game/Turn/TurnManager.h"
#include "Game/Turn/TurnEnd.h"
#include "Game/Turn/PlayerActionManager.h"

int currentTurn = 0; // 現在のターンを管理する変数
// 現在のターン状態
TurnState currentTurnState = TurnState::TurnStart;

// 現在の行動状態
//ActionState currentActionState = ActionState::None;

PlayerActionManager playerActionManager; // プレイヤーの行動管理オブジェクトのインスタンス

void TurnManager::UpdateTurn()
{
	switch (currentTurnState)
	{
	case TurnState::TurnStart:
		//currentActionState = ActionState::None;
		break;
	case TurnState::PlayerSelect:
		break;
	case TurnState::PlayerAction:
		// プレイヤーの行動を更新
		playerActionManager.UpdateAction();
		break;
	case TurnState::EnemyAction:
		break;
	case TurnState::TurnEnd:
		TurnEndCheck();
		break;
	default:
		break;
	}
}




// 状態変更
void TurnManager::SetTurnState(TurnState state)
{
	currentTurnState = state;
}
// 状態変更
