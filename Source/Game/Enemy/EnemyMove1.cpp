#include "Game/Enemy/EnemyMove1.h"

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

    const float movement = moveSpeed * deltaTime;

    switch (moveDirection)
    {
    case 0:
        // 右へ移動
        x += movement;
        break;
    case 1:
        // 下へ移動
        y += movement;
        break;
    case 2:
        // 左へ移動
        x -= movement;
        break;

    case 3:
        // 上へ移動
        y -= movement;
        break;
    }
    UpdatePosition(x, y);
    moveTimer.Update(deltaTime);

    if (moveTimer.IsFinished())
    {
        ++moveDirection;

        if (moveDirection >= 4)
        {
            // 4辺を移動し終わった
            moveDirection = 0;
            isMoved = true;
            return;
        }

        // 次の1辺を計測し始める
        moveTimer.Start(sideMoveTime);
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
    moveDirection = 0;
}
const void EnemyMove1::SetcanMove(bool state)
{
	canMove = state;
}

