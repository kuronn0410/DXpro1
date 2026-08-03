#pragma once
//#include "Timer/Timer.h"
#include "Game/Collision/HitDetection.h"
#include "Timer/Timer.h"
#include "Window/WindowState.h"
class EnemyMove1
{
public:
	bool Initialize(
		float EnemyimageWidth,
		float EnemyimageHeight,
		float EnemyScaleX,
		float EnemyScaleY
	);
	void Update(float& x,float& y);


	/*-----取得、指示の受付-----*/
	const bool GetisMoved() const;
	const HitDetection& GetHitDetection() const;
	const void ResetAction();
	const void SetcanMove(bool state);
private:
	//float moveX = 0.0f; // X方向の進む量
	//float moveY = 0.0f; // Y方向の進む量
	//float actualMovementX = 0.0f; // 実際に移動する量
	//float actualMovementY = 0.0f; // 実際に移動する量
	
	void enemy_move(float& x,float& y);
	Timer moveTimer;
	float velocityX = 0.0f;
	float velocityY = 0.0f;

	float moveSpeed = 100.0f;
	float moveTime = 3.0f;
	float deltaTime = 0.01f;


	float imageWidth = 0.0f; // 敵の画像の幅
	float imageHeight = 0.0f; // 敵の画像の高さ
	float scaleX = 0.0f; // 敵の画像のスケールX	
	float scaleY = 0.0f; // 敵の画像のスケールY

	/*-----取得、指示の受付-----*/
	bool canMove = true; // 敵が移動できるかどうかを判断する
	int moveDirection = 0;
	bool isMoved = false; // 一度動いたかどうかを判断する
	HitDetection hitDetection{};
	void UpdatePosition(float x, float y);
	void SelectRandomDirection();
};