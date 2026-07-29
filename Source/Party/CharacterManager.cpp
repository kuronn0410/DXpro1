#include "Party/CharacterManager.h"
#include "DebugTools/Debug.h"

/*
ゲーム開始時にキャラクター情報を初期化する関数

パーティーに編成するキャラクターを追加する関数
パーティーに編成したキャラクターを削除する関数
編成したパーティーを外部から取得する関数

*/


// ゲーム開始時にキャラクター情報を初期化する関数
bool CharacterManager::Initialize()
{
	Library::DebugTools::DebugLog("CharacterManager Initialize");
	playerStatusInitializer.Initialize();
	// 所持キャラクターの情報を取得
	characters = playerStatusInitializer.GetPlayerCharacters();
	return true;
}

// パーティーに編成画面で全キャラ表示するための関数
const std::vector<CharacterStatus>& CharacterManager::GetAllCharacters() const
{
	return characters;
}

bool CharacterManager::AddCharacterToParty(int characterIndex)
{
	if (partyCount < 4)
	{
		partyCharacter[partyCount] = characters[characterIndex];
		partyCount++;
		return true;
	}
	return false;
}
bool CharacterManager::RemoveCharacterFromParty(int partyIndex)
{
	if (partyIndex < partyCount)
	{
		//空いた場所を埋めるために後ろのキャラクターを前に詰める
		for (int i = partyIndex; i < partyCount - 1; i++)
		{
			partyCharacter[i] = partyCharacter[i + 1];
		}

		partyCount--;

		// 以前の最後の枠にデータが残るため初期化
		partyCharacter[partyCount] = CharacterStatus();
		return true;
	}
	return false;
}

const CharacterStatus* CharacterManager::GetAllPartyCharacter() const
{
	return partyCharacter;
}

//メモリの解放
void CharacterManager::Finalize()
{

}
