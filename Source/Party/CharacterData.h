#pragma once
#include "Party/CharacterType.h"
#include <string>
// キャラクターの初期データを格納する構造体
struct CharacterData
{
	CharacterType type;
	std::string name;
	std::string spritePath;
	int maxHp;
	int atk;
	int spd;
};
