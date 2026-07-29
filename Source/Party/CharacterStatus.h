#pragma once
#include "Party/CharacterType.h"
#include <string>
/*
typeとLevel、残りHP
最終的にゲーム中に使用するキャラクターのステータスを格納する構造体
*/
struct CharacterStatus
{
	CharacterType type;
	std::string spritePath;
	int level;
	int currentHp;
	int maxHp;
	int atk;
	int spd;
};
