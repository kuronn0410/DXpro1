#include "Game/Collision/Collision.h"
#include "Game/Collision/HitDetection.h"
/// <summary>
///	Õ“Ë”»’è
/// </summary>
/// <param name="a"> “G</param>
/// <param name="b"> ƒvƒŒƒCƒ„[</param>
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