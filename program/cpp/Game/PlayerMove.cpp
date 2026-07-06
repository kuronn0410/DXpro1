#include "header/Game/Player.h"
#include "header/Game/PlayerMove.h"
#include "header/WindowState.h"
#include "Library\Timer\Timer.h"
#include "Library\Input\Input.h"
#include <Windows.h>

float moveX = 0.0f; // X方向の進む量
float moveY = 0.0f; // Y方向の進む量

float player_x = 0.0f; // プレイヤーのX座標
float player_y = 0.0f; // プレイヤーのY座標

Timer moveTimer;
float deltaTime = 0.01f;
float finisheTime = 3.0f;

bool isXMoving = false;
bool isYMoving = false;


bool oldleft = false; // 左キーが押されていたかどうか
bool oldright = false; // 右キーが押されていたかどうか
bool oldup = false; // 上キーが押されていたかどうか
bool olddown = false; // 下キーが押されていたかどうか


// プレイヤーがX方向に移動できるかどうかを判定する関数
bool CanMoveX(float moveX)
{
	// プレイヤーの座標がウィンドウの範囲を超えないように制限
	if ((centerX + moveX) > g_windowWidth)
	{
		return false;
	}
	else if ((centerX + moveX) < 0)
	{
		return false;
	}
	return true;
}

// プレイヤーがY方向に移動できるかどうかを判定する関数
bool CanMoveY(float moveY)
{
	// プレイヤーの座標がウィンドウの範囲を超えないように制限
	
	if ((centerY + moveY) > g_windowHeight)
	{
		return false;
	}
	else if ((centerY + moveY) < 0)
	{
		return false;
	}
	return true;
}


void player_move_left()
{
	if (isXMoving)
	{
		return;
	}

	moveX = -1.5f * scaleX * 1000.0f;
	moveTimer.Start(finisheTime);
	isXMoving = true;
}


void player_move_right()
{
	if (isXMoving)
	{
		return;
	}
	moveX = 1.5f * scaleX * 1000; // 右に移動
	moveTimer.Start(finisheTime);
	isXMoving = true;
}

void player_move_up()
{
	if (isYMoving)
	{
		return;
	}	
	moveY = -1.5f * scaleY * 1000; // 上に移動
	moveTimer.Start(finisheTime);
	isYMoving = true;
}

void player_move_down()
{
	if (isYMoving)
	{
		return;
	}
	moveY = 1.5f * scaleY * 1000; // 下に移動
	moveTimer.Start(finisheTime);
	isYMoving = true;
}


void player_move_update()
{
	if (!isXMoving && !isYMoving)
	{
		return;
	}

	float movementX =(moveX / finisheTime) * deltaTime;
	float movementY = (moveY / finisheTime) * deltaTime;

	if (!CanMoveX(movementX))
	{
		isXMoving = false;
		return;
	}


	if(!CanMoveY(movementY))
	{
		isYMoving = false;
		return;
	}

	if(isXMoving)
	{
		player_x += movementX;
	}
	if(isYMoving)
	{
		player_y += movementY;
	}

	moveTimer.Update(deltaTime);
	//timer += Time::deltaTime;

	
	if (moveTimer.IsFinished())
	{
		isXMoving = false;
		isYMoving = false;
		moveX = 0.0f;
		moveY = 0.0f;
	}
		
	
}

void player_move()
{
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
}



