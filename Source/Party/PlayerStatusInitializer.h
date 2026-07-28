#pragma once
#include "Party/CharacterStatus.h"
#include "Party/CharacterDatabase.h"
#include "Party/CharacterType.h"
#include <vector>

// 所持しているキャラクターの情報を格納する構造体
struct PossessionCharacter
{
	CharacterType type;
	int level;
};

class PlayerStatusInitializer
{
public:
	// PlayerStatusの初期化(計算・保存)を行う関数
	void Initialize();

	const std::vector<CharacterStatus>& GetPlayerCharacters() const;
private:
	CharacterDatabase characterDatabase;
	//計算後のplayerStatausを格納する配列
	std::vector<CharacterStatus> playerCharacters;
	//セーブ機能がまだないから、初期化時に所持キャラクターを全て編成する
	PossessionCharacter possessionCharacters[6] = {
		{ CharacterType::Sword, 1 },
		{ CharacterType::Sword, 10 },
		{ CharacterType::Archer, 1 },
		{ CharacterType::Assassin, 1 },
		{ CharacterType::Astra, 1 },
		{ CharacterType::Martial, 1 }
	};

};

