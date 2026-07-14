#pragma once
#include "Timer/Timer.h"
#include "Game/Collision/HitDetection.h"

class EnemyMove1
{
public:
	void Update();
	// 敵のX座標を保持する変数
	//敵のX座標
	float Enemy_X = 0.0f;
	//敵のY座標
	float Enemy_Y = 0.0f;
	bool isMoved = false; // 一度動いたかどうかを判断する
	// 敵の移動処理時の当たり判定に使用する数値の計算をする関数
	void UpdatePosition();
	const HitDetection& GetHitDetection() const;
private:
	float moveX = 0.0f; // X方向の進む量
	float moveY = 0.0f; // Y方向の進む量
	float actualMovementX = 0.0f; // 実際に移動する量
	float actualMovementY = 0.0f; // 実際に移動する量
	Timer moveTimer;
	float deltaTime = 0.01f;
	float finisheTime = 3.0f;
	//壁までの移動時間を計算するための変数
	float moveTime = 0.0f;
	bool isXMoving = false;
	bool isYMoving = false;
	void enemy_move();
	HitDetection hitDetection{};


	int i;
};