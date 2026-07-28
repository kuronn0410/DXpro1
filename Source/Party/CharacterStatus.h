#pragma once
#include "Party/CharacterType.h"
/*
typeとLevel、残りHP
最終的にゲーム中に使用するキャラクターのステータスを格納する構造体
*/
struct CharacterStatus
{
	CharacterType type;
	int level;
	int currentHp;
	int maxHp;
	int atk;
	int spd;
};
