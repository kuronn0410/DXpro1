#include "header/Game/Player.h"
#include "header/input.h"
#include "header/Game/PlayerMove.h"
#include <Windows.h>


float player_x = 0.0f; // プレイヤーのX座標
float player_y = 0.0f; // プレイヤーのY座標

bool oldleft = false; // 左キーが押されていたかどうか
bool oldright = false; // 右キーが押されていたかどうか
bool oldup = false; // 上キーが押されていたかどうか
bool olddown = false; // 下キーが押されていたかどうか

void player_move_left()
{
	player_x -= 100.0f; // 左に移動
}

void player_move_right()
{
	player_x += 100.0f; // 右に移動
}

void player_move_up()
{
	player_y -= 100.0f; // 上に移動
}

void player_move_down()
{
	player_y += 100.0f; // 下に移動
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



