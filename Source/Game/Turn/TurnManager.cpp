#include "Game/Turn/TurnManager.h"



const TurnState& TurnManager::GetTurnState() const
{
	return currentTurnState;
}

// ó‘Ô•ÏX
void TurnManager::SetTurnState(TurnState state)
{
	currentTurnState = state;
}
// ó‘Ô•ÏX
