#pragma once
/*“G‚ÌŠî‘bƒf[ƒ^‚ÌŒ^*/
#include "Game/Enemy/EnemyType.h"
#include <string>

struct EnemyData
{
	EnemyType type;
	std::string spritePath;
	int maxHp;
	int atk;
	int spd;
};