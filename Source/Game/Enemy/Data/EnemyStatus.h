#pragma once
#include "Game/Enemy/EnemyType.h"
#include "Game/StartPos.h"
#include <string>

struct EnemyStatus
{
	EnemyType type;
	std::string spritePath;
	int currentHp;
	int maxHp;
	int atk;
	int spd;

	/*-ƒ|ƒWƒVƒ‡ƒ“-*/
	StartPos position;
};