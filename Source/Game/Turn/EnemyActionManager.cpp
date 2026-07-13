#include "Game/Turn/EnemyActionManager.h"
#include "Game/Enemy/Enemy.h"


Enemy enemy; // 敵オブジェクトのインスタンス	
void EnemyActionManager::UpdateAction()
{
	switch (currentActionState)
	{
	case ActionState::None:
		break;
	case ActionState::Aim:
		break;
	case ActionState::Move:

		enemy.Update();
		//playerHitEnemy.Update(); // プレイヤーが敵に当たったかどうかを更新
		break;
	case ActionState::End:

		break;
	default:
		break;
	}
}

void EnemyActionManager::SetActionState(ActionState state)
{
	currentActionState = state;
}