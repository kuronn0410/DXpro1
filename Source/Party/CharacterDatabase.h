#include <vector>
#include "Party/CharacterData.h"
#include <unordered_map>
/*
キャラクター初期データの管理
Typeでの検索での初期データの取得を行うクラス
*/
class CharacterDatabase
{
public:
	bool Initialize();
	// キャラクター初期データの作成を行う関数
	void CreateCharacterDatabase();
	// Typeでの検索での初期データの取得を行う関数
	const CharacterData* SearchCharacter(CharacterType type) const;

private:
	std::unordered_map<CharacterType, CharacterData> characterMap;
	// キャラクターの初期データを格納する配列
	CharacterData datas[5] = {
		{ CharacterType::Sword, "Sword", "Assets/Textures/Character/SWORD.png", 100, 20, 10 },
		{ CharacterType::Martial, "Martial", "Assets/Textures/Character/MARTIAL.png",80, 15, 15 },
		{ CharacterType::Archer, "Archer", "Assets/Textures/Character/ARCHER.png",70, 25, 20 },
		{ CharacterType::Assassin, "Assassin", "Assets/Textures/Character/ASSASSIN.png", 60, 30, 25 },
		{ CharacterType::Astra, "Astra", "Assets/Textures/Character/ASTRA.png", 90, 18, 12 }
	};
};