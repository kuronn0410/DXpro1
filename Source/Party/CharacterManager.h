#pragma once
#include <vector>
#include "Party/CharacterStatus.h"
#include "Party/PlayerStatusInitializer.h"


class CharacterManager
{
public:
	// ゲーム開始時にキャラクター情報を初期化する関数
	bool Initialize();
	//メモリの解放
	void Finalize();
	
	/*--取得--*/
	// パーティーに編成画面で全キャラ表示するための関数
	const std::vector<CharacterStatus>& GetAllCharacters() const;
	const CharacterStatus* GetAllPartyCharacter() const;
	int GetPartyCount() const;
	/*--指示受付--*/
	bool AddCharacterToParty(int characterIndex);
	bool RemoveCharacterFromParty(int partyIndex);

	
private:
	PlayerStatusInitializer playerStatusInitializer;
	//キャラクター全体の情報を格納する配列
	std::vector<CharacterStatus> characters;
	// パーティーに編成するキャラクターの情報を格納する配列
	CharacterStatus partyCharacter[4];

	int partyCount = 0;

};