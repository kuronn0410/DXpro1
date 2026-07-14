#include "Game/Turn/TurnManager.h"
#include "Game/Turn/PlayerActionManager.h"
#include "Game/Player/PlayerHitEnemy.h"
#include "Game/Player/Player.h"

PlayerHitEnemy playerHitEnemy; // プレイヤーが敵に当たったかどうかを管理するオブジェクトのインスタンス
Player player; // プレイヤーオブジェクトのインスタンス
void PlayerActionManager::UpdateAction()
{
	switch (currentActionState)
	{
	case ActionState::None:
		break;
	case ActionState::Aim:
		break;
	case ActionState::Move:
		player.Update();
		playerHitEnemy.Update(); // プレイヤーが敵に当たったかどうかを更新
		break;
	case ActionState::End:

		break;
	default:
		break;
	}
}

void PlayerActionManager::SetActionState(ActionState state)
{
	currentActionState = state;
}