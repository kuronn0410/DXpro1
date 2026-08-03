#include "Game/Enemy/EnemyMove1.h"
#include <random>
#include "Game/Collision/Collision.h"

bool EnemyMove1::Initialize(
    float EnemyimageWidth, 
    float EnemyimageHeight,
    float EnemyScaleX,
    float EnemyScaleY
    )
{
	imageWidth = EnemyimageWidth;
	imageHeight = EnemyimageHeight;
	scaleX = EnemyScaleX;
	scaleY = EnemyScaleY;
	isMoved = false;
	return true;
}


void EnemyMove1::Update(float& x,float& y)
{
    if(!canMove)
    {
        return;
	}
	UpdatePosition(x, y);
	enemy_move(x,y);
	// 敵の移動処理をここに記述
}
/*最初の位置に最終的に戻ってくる*/
void EnemyMove1::enemy_move(float& x,float& y)
{
    if (isMoved)
    {
        return;
    }

    const float movementX = velocityX * deltaTime;
    const float movementY = velocityY * deltaTime;

    // X方向の移動
    if (movementX != 0.0f)
    {
        x += movementX;
        UpdatePosition(x, y);

        if (!IsInsideScreen(
            static_cast<float>(g_windowWidth),
            static_cast<float>(g_windowHeight),
            hitDetection))
        {
            // 画面外へ出た移動を取り消す
            x -= movementX;

            // 左右を反転
            velocityX *= -1.0f;

            UpdatePosition(x, y);
        }
    }

    // Y方向の移動
    if (movementY != 0.0f)
    {
        y += movementY;
        UpdatePosition(x, y);

        if (!IsInsideScreen(
            static_cast<float>(g_windowWidth),
            static_cast<float>(g_windowHeight),
            hitDetection))
        {
            // 画面外へ出た移動を取り消す
            y -= movementY;

            // 上下を反転
            velocityY *= -1.0f;

            UpdatePosition(x, y);
        }
    }

    moveTimer.Update(deltaTime);

    if (moveTimer.IsFinished())
    {
        velocityX = 0.0f;
        velocityY = 0.0f;
        isMoved = true;
    }
	
}
//
//
void EnemyMove1::UpdatePosition(float x, float y)
{
	hitDetection.x = x;
	hitDetection.y = y;
	hitDetection.width = imageWidth * scaleX;
	hitDetection.height = imageHeight * scaleY;
}


void EnemyMove1::SelectRandomDirection()
{
    static std::mt19937 randomEngine{ std::random_device{}() };
    std::uniform_int_distribution<int> directionDistribution(0, 3);

    const int direction = directionDistribution(randomEngine);

    velocityX = 0.0f;
    velocityY = 0.0f;

    switch (direction)
    {
    case 0:
        // 左
        velocityX = -moveSpeed;
        break;

    case 1:
        // 右
        velocityX = moveSpeed;
        break;

    case 2:
        // 上
        velocityY = -moveSpeed;
        break;

    case 3:
        // 下
        velocityY = moveSpeed;
        break;
    }
}

/*-----取得、指示の受付-----*/
const bool EnemyMove1::GetisMoved() const
{
	return isMoved;	
}
const HitDetection& EnemyMove1::GetHitDetection() const
{
		return hitDetection;
}
const void EnemyMove1::	ResetAction()
{
	isMoved = false;

    SelectRandomDirection();
    moveTimer.Start(moveTime);
}
const void EnemyMove1::SetcanMove(bool state)
{
	canMove = state;
}

