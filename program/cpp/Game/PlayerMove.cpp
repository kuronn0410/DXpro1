#include "header/Game/Player.h"
#include "header/input.h"
#include "header/Game/PlayerMove.h"
#include "header/WindowState.h"
#include "header/TimeManager.h"
#include <Windows.h>
#include <iostream>

float moveX = 0.0f; // X方向の進む量
float moveY = 0.0f; // Y方向の進む量

float player_x = 0.0f; // プレイヤーのX座標
float player_y = 0.0f; // プレイヤーのY座標

float timer = 0.0f;
float endTime = 3.0f;
bool isMoving = false;


bool oldleft = false; // 左キーが押されていたかどうか
bool oldright = false; // 右キーが押されていたかどうか
bool oldup = false; // 上キーが押されていたかどうか
bool olddown = false; // 下キーが押されていたかどうか



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
	if (isMoving)
	{
		return;
	}

	moveX = -1.5f * scaleX * 1000.0f;
	timer = 0.0f;
	isMoving = true;
}


void player_move_right()
{
	moveX = 1.5f * scaleX * 1000; // 右に移動
	if(CanMoveX(moveX))
	{
		player_x += moveX; // 右に移動
	}
}

void player_move_up()
{
	moveY = -1.5f * scaleY * 1000; // 上に移動
	if (CanMoveY(moveY))
	{
		player_y += moveY; // 上に移動
	}
	
}

void player_move_down()
{
	moveY = 1.5f * scaleY * 1000; // 下に移動
	if(CanMoveY(moveY))
	{
		player_y += moveY; // 下に移動
	}
}


void player_move_update()
{
	if (!isMoving)
	{
		return;
	}

	float movement =
		(moveX / endTime) * Time::deltaTime;

	if (!CanMoveX(movement))
	{
		isMoving = false;
		return;
	}

	player_x += movement;
	timer += Time::deltaTime;

	if (timer >= endTime)
	{
		isMoving = false;
		timer = 0.0f;
	}
}

void player_move()
{
	// 現在のキーの状態を取得
	bool nowleft = (GetAsyncKeyState(VK_LEFT) & 0x8000) != 0;
	bool nowright = (GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0;
	bool nowup = (GetAsyncKeyState(VK_UP) & 0x8000) != 0;
	bool nowdown = (GetAsyncKeyState(VK_DOWN) & 0x8000) != 0;

	// プレイヤーの移動処理をここに記述
	if (!nowleft && oldleft)
	{
		// 左キーが押されていた場合の処理
		player_move_left();	
		
	}
	if (!nowright && oldright)
	{
		// 右キーが押されていた場合の処理
		player_move_right();
	}
	if (!nowup && oldup)
	{
		// 上キーが押されていた場合の処理
		player_move_up();
	}
	if (!nowdown && olddown)
	{
		// 下キーが押されていた場合の処理
		player_move_down();
	}

	oldleft = nowleft;
	oldright = nowright;
	oldup = nowup;
	olddown = nowdown;

}



