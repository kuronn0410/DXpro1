#include "Game/Turn/TurnManager.h"
#include "Game/Turn/TurnEnd.h"

int currentTurn = 0; // 現在のターンを管理する変数
// 現在のターン状態
TurnState currentTurnState = TurnState::TurnStart;

// 現在の行動状態
ActionState currentActionState = ActionState::None;

void TurnManager::UpdateTurn()
{
	switch (currentTurnState)
	{
	case TurnState::TurnStart:
		currentActionState = ActionState::None;
		break;
	case TurnState::PlayerSelect:
		break;
	case TurnState::PlayerAction:
		UpdateAction();
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

void TurnManager::UpdateAction()
{
	switch (currentActionState)
	{
	case ActionState::None:
		break;
	case ActionState::Aim:
		break;
	case ActionState::Move:
		break;
	case ActionState::End:
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
void TurnManager::SetActionState(ActionState state)
{
	currentActionState = state;
}