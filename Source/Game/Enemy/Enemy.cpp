#include "Game/Enemy/Enemy.h"
#include "Game/GameConfig.h"
#include "Game/Turn/TurnManager.h"


//extern TurnManager turnManager;

//bool Enemy::Initialize()
//{
//
//	if (!sprite.Init(
//		g_device,
//		"Assets\\Textures\\Goal.png"))
//	{
//		return false;
//	}
//
//	enemyMove1.Enemy_X = GameConfig::EnemyStartX;
//	enemyMove1.Enemy_Y = GameConfig::EnemyStartY;
//	//initに移す
//	
//	imageInfo = sprite.GetImageInfo();
//	scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
//	scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;
//	// 敵の当たり判定の初期化
//	enemyMove1.UpdatePosition();
//
//	enemyStatus.maxHp = GameConfig::EnemyHp;
//	enemyStatus.atk = GameConfig::EnemyDamage;
//
//	return true;
//}
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