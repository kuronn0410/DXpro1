
#pragma once
#include "Timer/Timer.h"
#include "Game/Collision/HitDetection.h"

// PlayerMove.h
class PlayerMove
{
public:
	void Initialize(
		float startX,
		float startY,
		float PlayerimageWidth,
		float PlayerimageHeight,
		float PlayerScaleX,
		float PlayerScaleY
	);
	void Update(
		float PlayerScaleX,
		float PlayerScaleY,
		float PlayerimageWidth,
		float PlayerimageHeight
	);

	// プレイヤーの移動処理時の当たり判定に使用する数値の計算をする関数
	void UpdatePosition();

	/*-----取得、指示の受付-----*/
	const HitDetection& GetHitDetection() const;
	void ResetAction();// プレイヤーの移動フラグをリセットする関数
	/// <summary>
	/// プレイヤーが移動できるかどうかを管理してるboolを変更する
	/// </summary>
	/// <param name="state">Ture 移動可能/False 移動不可</param>
	void SetCanMoveState(bool state); 
	/// <summary>
	/// isMovedの値を取得する関数
	/// </summary>
	/// <returns></returns>
	bool GetisMoved() const;
	
	float player_x; // プレイヤーのX座標
	float player_y; // プレイヤーのY座標
	
private:

	float moveX = 0.0f; // X方向の進む量
	float moveY = 0.0f; // Y方向の進む量

	// プレイヤーの移動に関するタイマー
	Timer moveTimer;
	float deltaTime = 0.01f;
	float finisheTime = 3.0f;

	bool isXMoving = false;
	bool isYMoving = false;

	bool isMoved = false; // 一度動いたかどうかを判断する
	bool canMove = true; // プレイヤーが移動できるかどうかを判断する

	void player_move();
	void player_move_left();
	void player_move_right();
	void player_move_up();
	void player_move_down();
	void player_move_update();

	float imageWidth = 0.0f;
	float imageHeight = 0.0f;
	float scaleX = 0.0f;
	float scaleY = 0.0f;

	HitDetection hitDetection{};

};
