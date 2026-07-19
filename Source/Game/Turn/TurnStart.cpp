#include "TurnStart.h"
#include "Game/Player/PlayerMove.h"
#include "Game/Player/PlayerHitEnemy.h"
#include "Game/Turn/PlayerActionManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/TurnManager.h"	


//そのターンを始めるための準備
//フラグのリセット
//行動状態の初期化


extern PlayerMove playerMove;
extern PlayerHitEnemy playerHitEnemy;
extern PlayerActionManager playerActionManager;
extern EnemyActionManager enemyActionManager;
extern TurnManager turnManager;



void TurnStart()
{
	//isTurnEnd = false;
	// プレイヤーの移動フラグをリセット
	playerMove.isMoved = false;
	// プレイヤーが敵に当たったかどうかのフラグをリセット
	playerHitEnemy.isDamage = false;

	turnManager.SetTurnState(TurnState::PlayerAction);
	// プレイヤーの行動状態をMoveに設定
	playerActionManager.SetActionState(ActionState::Move);
	// 敵の行動状態をMoveに設定
	enemyActionManager.SetActionState(EnemyActionState::Move);
}