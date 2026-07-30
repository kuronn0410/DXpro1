#include "Game/Turn/TurnManager.h"
#include "Game/Turn/PlayerActionManager.h"
#include "Game/Player/PlayerHitEnemy.h"
#include "Game/Player/Player.h"

/*PlayerHitEnemy playerHitEnemy;*/ // プレイヤーが敵に当たったかどうかを管理するオブジェクトのインスタンス
void PlayerActionManager::UpdateAction(/*PlayerManager& playerManager*/)
{
	//switch (currentActionState)
	//{
	//case ActionState::None:
	//	break;
	//case ActionState::Aim:
	//	break;
	//case ActionState::Move:
	//	playerManager.Update(turnManager, enemyActionManager, *this);
	//	playerHitEnemy.Update(); // プレイヤーが敵に当たったかどうかを更新
	//	break;
	//case ActionState::End:
	//	//playerHitEnemy.isDamage = false; // ダメージフラグをリセット
	//	currentActionState = ActionState::None; // 状態をNoneに戻す
	//	break;
	//default:
	//	break;
	//}
}

void PlayerActionManager::SetActionState(ActionState state)
{
	currentActionState = state;
}