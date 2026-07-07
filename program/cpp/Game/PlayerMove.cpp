#include "header/Game/Player.h"
#include "header/Game/PlayerMove.h"
#include "header/WindowState.h"
#include "Library\Timer\Timer.h"
#include "Library\Input\Input.h"
#include <Windows.h>

float moveX = 0.0f; // X方向の進む量
float moveY = 0.0f; // Y方向の進む量
float actualMovementX = 0.0f; // 実際に移動する量
float actualMovementY = 0.0f; // 実際に移動する量
float checkX = 0.0f; // 壁に到達したかどうかを確認するための変数
float checkY = 0.0f; // 壁に到達したかどうかを確認するための変数

float player_x = 0.0f; // プレイヤーのX座標
float player_y = 0.0f; // プレイヤーのY座標

Timer moveTimer;
//Timer movetimer
float deltaTime = 0.01f;
float finisheTime = 3.0f;
//壁までの移動時間を計算するための変数
float moveTime = 0.0f;

bool isXMoving = false;
bool isYMoving = false;
bool reflecting_moveX = false; // 反射移動中かどうか
bool reflecting_moveY = false; // 反射移動中かどうか

bool oldleft = false; // 左キーが押されていたかどうか
bool oldright = false; // 右キーが押されていたかどうか
bool oldup = false; // 上キーが押されていたかどうか
bool olddown = false; // 下キーが押されていたかどうか


// プレイヤーがX方向に移動できるかどうかを判定する関数
float LimitMoveX(float moveX)
{
	//移動後のプレイヤーの中心座標を計算
	float nextCenterX = centerX + moveX;
	// プレイヤーの座標がウィンドウの範囲を超えないように制限
	if (nextCenterX > g_windowWidth)
	{
		//右端までの距離だけ返す
		return g_windowWidth - centerX;
	}
	else if (nextCenterX < 0)
	{
		//左端までの距離だけ返す
		return -centerX;
	}
	return moveX;
}

// プレイヤーがY方向に移動できるかどうかを判定する関数
float LimitMoveY(float moveY)
{
	// 移動後のプレイヤーの中心座標を計算
	float nextCenterY = centerY + moveY;
	// プレイヤーの座標がウィンドウの範囲を超えないように制限	
	
	if (nextCenterY > g_windowHeight)
	{
		//下端までの距離だけ返す
		return g_windowHeight - centerY;
	}
	else if (nextCenterY < 0)
	{
		//上端までの距離だけ返す
		return -centerY;
	}
	return moveY;
}


void player_move_left()
{
	if (isXMoving)
	{
		return;
	}

	moveX = -1.5f * scaleX * 1000.0f;
	actualMovementX = LimitMoveX(moveX);//壁又は普通の移動量を計算
	checkX = moveX - actualMovementX;

	moveTime = finisheTime*(actualMovementX/ moveX);
	//壁までの移動時間を計算するための変数
	moveTimer.Start(moveTime);
	isXMoving = true;
}


void player_move_right()
{
	if (isXMoving)
	{
		return;
	}
	moveX = 1.5f * scaleX * 1000; // 右に移動
	actualMovementX = LimitMoveX(moveX);// 移動後のプレイヤーの中心座標を計算
	checkX = moveX - actualMovementX;
	moveTime = finisheTime*(actualMovementX/ moveX);
	moveTimer.Start(moveTime);
	isXMoving = true;
}

void player_move_up()
{
	if (isYMoving)
	{
		return;
	}	
	moveY = -1.5f * scaleY * 1000; // 上に移動
	actualMovementY = LimitMoveY(moveY);// 移動後のプレイヤーの中心座標を計算
	checkY = moveY - actualMovementY;
	moveTime = finisheTime * (actualMovementY / moveY);
	moveTimer.Start(moveTime);
	isYMoving = true;
}

void player_move_down()
{
	if (isYMoving)
	{
		return;
	}
	moveY = 1.5f * scaleY * 1000; // 下に移動
	actualMovementY = LimitMoveY(moveY);// 移動後のプレイヤーの中心座標を計算
	checkY = moveY - actualMovementY;
	moveTime = finisheTime * (actualMovementY / moveY);
	moveTimer.Start(moveTime);
	isYMoving = true;
}


//指定された方向移動するだけ
//壁までの移動
void player_move_update()
{
	if (!isXMoving && !isYMoving)
	{
		return;
	}

	float movementX =(actualMovementX / moveTime) * deltaTime;
	float movementY = (actualMovementY / moveTime) * deltaTime;

	
	if(isXMoving)
	{
		player_x += movementX;
	}
	if(isYMoving)
	{
		player_y += movementY;
	}

	moveTimer.Update(deltaTime);
	//timer += Time::deltaTime;s
	
	if (moveTimer.IsFinished())
	{
		isXMoving = false;
		isYMoving = false;

		reflecting_moveX = checkX != 0.0f;
		reflecting_moveY = checkY != 0.0f;

		if (reflecting_moveX || reflecting_moveY)
		{
			moveTimer.Start(finisheTime - moveTime);
		}
	}
}

//壁に当たったときに逆方向に移動する関数
void player_inversemove_update()
{
	
	//反射移動中でなければ何もしない
	if (!reflecting_moveX && !reflecting_moveY)
	{
		return;
	}

	float movementX = (checkX / (finisheTime - moveTime)) * deltaTime;
	float movementY = (checkY / (finisheTime - moveTime)) * deltaTime;
	//指定された方向移動するだけ
	//壁まで
	if (reflecting_moveX)
	{
		player_x -= movementX;
	}
	if (reflecting_moveY)
	{
		player_y -= movementY;
	}
	moveTimer.Update(deltaTime);
	if (moveTimer.IsFinished())
	{
		reflecting_moveX = false;
		reflecting_moveY = false;

		checkX = 0.0f;
		checkY = 0.0f;
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
	player_move_update();
	player_inversemove_update();
		
}



