#include "Game/Collision/Collision.h"
#include "Game/Collision/HitDetection.h"
/// <summary>
///衝突判定　(キャラクター同士の当たり判定)
/// </summary>
/// <param name="a"> 敵</param>
/// <param name="b"> プレイヤー</param>
/// <returns></returns>
bool IsHit(const HitDetection& a, const HitDetection& b)
{
	if (a.x + a.width >= b.x &&
		a.x <= b.x + b.width &&
		a.y + a.height >= b.y &&
		a.y <= b.y + b.height)
	{
		return true;
	}
	return false;
}
/// <summary>
///衝突判定　(壁とキャラ)
/// </summary>
/// <param name="a"> キャラクター</param>
/// <returns></returns>
bool IsInsideScreen(float windowWidth,float windowHeight,const HitDetection& a)
{
	
	return   
		a.x >= 0.0f &&
		a.y >= 0.0f &&
		a.x + a.width <= windowWidth &&
		a.y + a.height <= windowHeight;;
}

/// <summary>
///衝突判定　(壁とキャラ)
/// </summary>
/// <param name="a"> キャラクター</param>
/// <returns></returns>
bool IsOutsideScreen(const HitDetection& a)
{
	//// 画面外判定
	//if (a.x + a.width < 0 || a.x > g_windowWidth ||
	//	a.y + a.height < 0 || a.y > g_windowHeight)
	//{
	//	return true;
	//}
	//return false;
	return true;
}