//#include "Game/Enemy/EnemyMove1.h"
//#include "Game/Enemy/Enemy.h"
//
//extern Enemy enemy;
//void EnemyMove1::Update()
//{
//	UpdatePosition();
//	enemy_move();
//	// “G‚ÌˆÚ“®ˆ—‚ğ‚±‚±‚É‹Lq
//}
//
//
//void EnemyMove1::enemy_move()
//{
//	if(i<10)
//	{
//		Enemy_X += 3.0f;
//	}
//	else
//	{
//		isMoved = true;
//		i = 0;
//	}
//	i++;
//	UpdatePosition();
//}
//
//
//void EnemyMove1::UpdatePosition()
//{
//	hitDetection.x = Enemy_X;
//	hitDetection.y = Enemy_Y;
//	hitDetection.width = static_cast<float>(enemy.imageInfo.Width) * enemy.scaleX;
//	hitDetection.height = static_cast<float>(enemy.imageInfo.Height) * enemy.scaleY;
//}
//
//const HitDetection& EnemyMove1::GetHitDetection() const
//{
//	return hitDetection;
//}
//
