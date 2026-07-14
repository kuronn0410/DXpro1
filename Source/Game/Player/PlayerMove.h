
#pragma once
#include "Timer/Timer.h"
#include "Game/Collision/HitDetection.h"

// PlayerMove.h
class PlayerMove
{
public:
	void Update();
	// プレイヤーのX座標を保持する変数
	float player_x; // プレイヤーのX座標
	// プレイヤーのY座標を保持する変数
	float player_y; // プレイヤーのY座標
	bool isMoved = false; // 一度動いたかどうかを判断する
	// プレイヤーの移動処理時の当たり判定に使用する数値の計算をする関数
	void UpdatePosition();
	const HitDetection& GetHitDetection() const;

private:
	
	float moveX = 0.0f; // X方向の進む量
	float moveY = 0.0f; // Y方向の進む量
	float actualMovementX = 0.0f; // 実際に移動する量
	float actualMovementY = 0.0f; // 実際に移動する量
	float checkX = 0.0f; // 壁に到達したかどうかを確認するための変数
	float checkY = 0.0f; // 壁に到達したかどうかを確認するための変数

	Timer moveTimer;
	float deltaTime = 0.01f;
	float finisheTime = 3.0f;
	//壁までの移動時間を計算するための変数
	float moveTime = 0.0f;

	bool isXMoving = false;
	bool isYMoving = false;
	bool reflecting_moveX = false; // 反射移動中かどうか
	bool reflecting_moveY = false; // 反射移動中かどうか


	void player_move();
	float LimitMoveX(float moveX);
	float LimitMoveY(float moveY);
	void player_move_left();
	void player_move_right();
	void player_move_up();
	void player_move_down();

	void player_inversemove_update();
	void player_move_update();

	HitDetection hitDetection{};

};
