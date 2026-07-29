#pragma once
#include <vector>
#include "Party/CharacterStatus.h"	
#include "Party/CharacterManager.h"
#include "UI/Button/Button.h"
#include "Party/CharacterManager.h"
class CharacterCompositionUI
{
public:
	// キャラクター編成UIの初期化を行う関数
	bool Initialize(CharacterManager& manager);
	// キャラクター編成UIの更新を行う関数
	void Update();
	// キャラクター編成UIの描画を行う関数
	void Draw();
	void Finalize();

	bool CheckIsCharacterInParty(int characterIndex) const;
private:
	std::vector<CharacterStatus> characters;
	int TotalCharacterNumber = 0;
	Button characterButton[6];
	Button partyButton[4];
	CharacterManager* characterManager;
	void AddCharacterToParty(int characterIndex);
	//入れられるかどうか判定する値を受け取る
	int partyCount = 0;
	//パーティに追加されたキャラクターのインデックスを保持する配列
	int AddpartyIndex[4] = {};
};