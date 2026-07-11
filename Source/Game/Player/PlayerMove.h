
#pragma once
#include "Timer/Timer.h"

// PlayerMove.h
class PlayerMove
{
public:
	void Update();
	// プレイヤーのX座標を保持する変数
	float player_x; // プレイヤーのX座標
	// プレイヤーのY座標を保持する変数
	float player_y; // プレイヤーのY座標

private:
	
	////playerの中心座標のXを保持する変数
	//float centerX;
	////playerの中心座標のYを保持する変数
	//float centerY;
	// プレイヤーの移動処理を行う関数
	float moveX = 0.0f; // X方向の進む量
	float moveY = 0.0f; // Y方向の進む量
	float actualMovementX = 0.0f; // 実際に移動する量
	float actualMovementY = 0.0f; // 実際に移動する量
	float checkX = 0.0f; // 壁に到達したかどうかを確認するための変数
	float checkY = 0.0f; // 壁に到達したかどうかを確認するための変数

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

	void player_move();
	float LimitMoveX(float moveX);
	float LimitMoveY(float moveY);
	void player_move_left();
	void player_move_right();
	void player_move_up();
	void player_move_down();

	void player_inversemove_update();
	void player_move_update();

};
