#pragma once

#include "Game/Collision/HitDetection.h"

/// <summary>
///	衝突判定
/// </summary>
/// <param name="a"> 敵</param>
/// <param name="b"> プレイヤー</param>
/// <returns></returns>
bool IsHit(const HitDetection& a, const HitDetection& b);
/// <summary>
///		
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
bool IsInsideScreen(float windowWidth, float windowHeight,const HitDetection& a);
/// <summary>
///衝突判定　(壁とキャラ)
/// </summary>
/// <param name="a"> キャラクター</param>
/// <returns></returns>
bool IsOutsideScreen(const HitDetection& a);