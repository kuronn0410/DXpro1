#include "Game/Player/Player.h"
#include "Game/Player/PlayerMove.h"
#include "Window/WindowState.h"
#include "Input/Input.h"
#include <Windows.h>

extern Player player;
// プレイヤーがX方向に移動できるかどうかを判定する関数
void PlayerMove::Update()
{
	player_move();
}
float PlayerMove::LimitMoveX(float moveX)
{
	//移動後のプレイヤーの中心座標を計算
	float nextCenterX = player.centerX + moveX;
	// プレイヤーの座標がウィンドウの範囲を超えないように制限
	if (nextCenterX > g_windowWidth)
	{
		//右端までの距離だけ返す
		return g_windowWidth - player.centerX;
	}
	else if (nextCenterX < 0)
	{
		//左端までの距離だけ返す
		return -player.centerX;
	}
	return moveX;
}

// プレイヤーがY方向に移動できるかどうかを判定する関数
float PlayerMove::LimitMoveY(float moveY)
{
	// 移動後のプレイヤーの中心座標を計算
	float nextCenterY = player.centerY + moveY;
	// プレイヤーの座標がウィンドウの範囲を超えないように制限	
	
	if (nextCenterY > g_windowHeight)
	{
		//下端までの距離だけ返す
		return g_windowHeight - player.centerY;
	}
	else if (nextCenterY < 0)
	{
		//上端までの距離だけ返す
		return -player.centerY;
	}
	return moveY;
}


void PlayerMove::player_move_left()
{
	if (isXMoving)
	{
		return;
	}

	moveX = -1.5f * player.GetScaleX() * 1000;
	actualMovementX = LimitMoveX(moveX);//壁又は普通の移動量を計算
	checkX = moveX - actualMovementX;

	moveTime = finisheTime*(actualMovementX/ moveX);
	//壁までの移動時間を計算するための変数
	moveTimer.Start(moveTime);
	isXMoving = true;
}


void PlayerMove::player_move_right()
{
	if (isXMoving)
	{
		return;
	}
	moveX = 1.5f * player.GetScaleX() * 1000; // 右に移動
	actualMovementX = LimitMoveX(moveX);// 移動後のプレイヤーの中心座標を計算
	checkX = moveX - actualMovementX;
	moveTime = finisheTime*(actualMovementX/ moveX);
	moveTimer.Start(moveTime);
	isXMoving = true;
}

void PlayerMove::player_move_up()
{
	if (isYMoving)
	{
		return;
	}	
	moveY = -1.5f * player.GetScaleY() * 1000; // 上に移動
	actualMovementY = LimitMoveY(moveY);// 移動後のプレイヤーの中心座標を計算
	checkY = moveY - actualMovementY;
	moveTime = finisheTime * (actualMovementY / moveY);
	moveTimer.Start(moveTime);
	isYMoving = true;
}

void PlayerMove::player_move_down()
{
	if (isYMoving)
	{
		return;
	}
	moveY = 1.5f * player.GetScaleY() * 1000; // 下に移動
	actualMovementY = LimitMoveY(moveY);// 移動後のプレイヤーの中心座標を計算
	checkY = moveY - actualMovementY;
	moveTime = finisheTime * (actualMovementY / moveY);
	moveTimer.Start(moveTime);
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
void PlayerMove::player_inversemove_update()
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

void PlayerMove::player_move()
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



