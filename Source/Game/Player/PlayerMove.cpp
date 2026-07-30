#include "Game/Player/PlayerMove.h"
#include "Window/WindowState.h"
#include "Input/Input.h"
#include <Windows.h>
#include "Game/Collision/Collision.h"
#include <stdio.h>


void PlayerMove::Initialize(
	float startX,
	float startY,
	float PlayerimageWidth,
	float PlayerimageHeight,
	float PlayerScaleX,
	float PlayerScaleY
)
{
	player_x = startX;
	player_y = startY;
	hitDetection.x = player_x;
	hitDetection.y = player_y;
	hitDetection.width = PlayerimageWidth * PlayerScaleX;
	hitDetection.height = PlayerimageHeight * PlayerScaleY;
}

// プレイヤーがX方向に移動できるかどうかを判定する関数
void PlayerMove::Update(
	float PlayerScaleX,
	float PlayerScaleY,
	float PlayerimageWidth,
	float PlayerimageHeight)
{

	imageWidth = PlayerimageWidth;
	imageHeight = PlayerimageHeight;
	scaleX = PlayerScaleX;
	scaleY = PlayerScaleY;
	
	UpdatePosition();
	player_move();
	UpdatePosition();
}

void PlayerMove::player_move_left()
{
	if (isXMoving)
	{
		return;
	}

	moveX = -1.5f * scaleX * 10000; // 左に移動
	moveTimer.Start(finisheTime);
	isXMoving = true;
}


void PlayerMove::player_move_right()
{
	if (isXMoving)
	{
		return;
	}
	moveX = 1.5f * scaleX * 10000; // 右に移動
	moveTimer.Start(finisheTime);
	isXMoving = true;
}

void PlayerMove::player_move_up()
{
	if (isYMoving)
	{
		return;
	}	
	moveY = -1.5f * scaleY * 10000; // 上に移動
	moveTimer.Start(finisheTime);
	isYMoving = true;
}

void PlayerMove::player_move_down()
{
	if (isYMoving)
	{
		return;
	}
	moveY = 1.5f * scaleY * 10000; // 下に移動
	moveTimer.Start(finisheTime);
	isYMoving = true;
}


//指定された方向移動するだけ
//壁までの移動
void PlayerMove::player_move_update()
{
	if (!isXMoving && !isYMoving)
	{
		return;
	}

	float movementX =(moveX/ finisheTime) * deltaTime;
	float movementY = (moveY / finisheTime) * deltaTime;

	if(isXMoving)
	{

		player_x += movementX;
		UpdatePosition();
		if (!IsInsideScreen(g_windowWidth, g_windowHeight, hitDetection))
		{
			player_x -= movementX;
			moveX *= -1.0f;
			UpdatePosition();
		}
		

	}
	if(isYMoving)
	{
		player_y += movementY;
		UpdatePosition();
		if (!IsInsideScreen(g_windowWidth, g_windowHeight, hitDetection))
		{
			player_y -= movementY;
			moveY *= -1.0f;
			UpdatePosition();
		}
		
	}

	moveTimer.Update(deltaTime);
	//timer += Time::deltaTime;s
	
	if (moveTimer.IsFinished())
	{
		isXMoving = false;
		isYMoving = false;
		isMoved = true;
		
	}
}


void PlayerMove::player_move()
{
	if(isMoved)
	{
		return;
	}
	if (GetKeyUp(VK_LEFT))
	{
		player_move_left();
	}

	if (GetKeyUp(VK_RIGHT))
	{
		player_move_right();
	}

	if (GetKeyUp(VK_UP))
	{
		player_move_up();
	}

	if (GetKeyUp(VK_DOWN))
	{
		player_move_down();
	}
	player_move_update();
	//player_inversemove_update();
		
}

const HitDetection& PlayerMove::GetHitDetection() const
{
	return hitDetection;
}

void PlayerMove::UpdatePosition()
{
	hitDetection.x = player_x;
	hitDetection.y = player_y;
	hitDetection.width = imageWidth * scaleX;
	hitDetection.height = imageHeight * scaleY;
}

void PlayerMove::ResetAction()
{
	isMoved = false;
}



