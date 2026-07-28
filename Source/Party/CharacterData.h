#pragma once
#include "Party/CharacterType.h"
// キャラクターの初期データを格納する構造体
struct CharacterData
{
	CharacterType type;
	const char* name;
	const char* spritePath;
	int maxHp;
	int atk;
	int spd;
};
