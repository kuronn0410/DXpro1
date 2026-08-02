#include "Game/Enemy/Enemy.h"


//extern TurnManager turnManager;

bool Enemy::Initialize(EnemyStatus enemyStatus)
{

	if (!sprite.Init(
		g_device,
		enemyStatus.spritePath.c_str()))
	{
		return false;
	}
	enemyMove1.Initialize(imageInfo.Width, imageInfo.Height, scaleX, scaleY);
	Enemy_x = enemyStatus.position.startx;
	Enemy_y = enemyStatus.position.starty;
	
	imageInfo = sprite.GetImageInfo();

	imageWidth = static_cast<float>(imageInfo.Width);
	imageHeight = static_cast<float>(imageInfo.Height);

	scaleX = static_cast<float>(g_windowWidth) / imageWidth * 0.25f;
	scaleY = static_cast<float>(g_windowHeight) / imageHeight * 0.25f;
	// 敵の当たり判定の初期化
	/*enemyMove1.UpdatePosition();*/

	enemyStatus.maxHp = enemyStatus.maxHp;
	enemyStatus.atk = enemyStatus.atk;

	return true;
}
//
//void Enemy::Update()
//{
//	enemyMove1.Update();
//	if (enemyMove1.isMoved)
//	{
//		turnManager.SetTurnState(TurnState::TurnEnd);
//		//ターンエンド時にプレイヤーの移動フラグをリセットする
//		enemyMove1.isMoved = false;
//		// 状態変更
//		//playerActionManager.SetActionState(ActionState::None);
//	}
//	if(enemyStatus.maxHp <= 0)
//	{
//		IsAlive = false;
//	}
//
//	// 敵の更新処理をここに記述
//}
//
//
//void Enemy::Finalize()
//{
//	sprite.Release();
//}
//
//const HitDetection& Enemy::GetHitDetection() const
//{
//	return enemyMove1.GetHitDetection();
//}
//
//void Enemy::DamageToCharacter(int damage)
//{
//	enemyStatus.maxHp -= damage;
//	if (enemyStatus.maxHp <= 0)
//	{
//		IsAlive = false;
//	}
//}


//bool Enemy::Initialize()
//{
//	return true;
//}

bool Enemy::Update()
{
	enemyMove1.Update(Enemy_x, Enemy_y);
	if(enemyMove1.GetisMoved())
	{
		return false;
	}
	return true;
}

void Enemy::Finalize()
{

}


/*-----取得、指示の受付-----*/
bool Enemy::GetIsAlive() const
{
	return IsAlive;
}

void Enemy::StartTurn()
{
	enemyMove1.ResetAction();
}