#include "Game/Enemy/Enemy.h"


//extern TurnManager turnManager;

bool Enemy::Initialize(EnemyStatus status)
{

	if (!sprite.Init(
		g_device,
		status.spritePath.c_str()))
	{
		return false;
	}
	
	Enemy_x = status.position.startx;
	Enemy_y = status.position.starty;
	
	imageInfo = sprite.GetImageInfo();

	imageWidth = static_cast<float>(imageInfo.Width);
	imageHeight = static_cast<float>(imageInfo.Height);

	scaleX = static_cast<float>(g_windowWidth) / imageWidth * 0.25f;
	scaleY = static_cast<float>(g_windowHeight) / imageHeight * 0.25f;
	// “G‚Ì“–‚½‚è”»’è‚Ì‰Šú‰»
	/*enemyMove1.UpdatePosition();*/

	enemyStatus.maxHp = status.maxHp;
	enemyStatus.atk = status.atk;
	enemyMove1.Initialize(imageInfo.Width, imageInfo.Height, scaleX, scaleY);
	return true;
}

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


/*-----æ“¾-----*/
bool Enemy::GetIsAlive() const
{
	return IsAlive;
}

const HitDetection& Enemy::GetHitDetection() const
{
	return enemyMove1.GetHitDetection();
}

int Enemy::GetAttack() const
{
	return enemyStatus.atk;
}


/*-----w¦‚Ìó•t-----*/
void Enemy::StartTurn()
{
	enemyMove1.ResetAction();
}

void Enemy::TakeDamage(int damage)
{
	enemyStatus.currentHp -= damage;
	if (enemyStatus.currentHp <= 0)
	{
		IsAlive = false;
	}
}