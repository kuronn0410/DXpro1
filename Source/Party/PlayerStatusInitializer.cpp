#include "Party/PlayerStatusInitializer.h"
/*
所持しているキャラクター(PlayerStatus)の初期化を行い実態を作成するクラス
*/

void PlayerStatusInitializer::Initialize()
{
	characterDatabase.Initialize(); // CharacterDatabaseの初期化
	// 所持キャラクターの初期化処理をここに記述
	for(int i = 0; i < 6; ++i)
	{
		//所持キャラのTypeを元にCharacterDatabaseから初期データを取得
		const CharacterData* data = characterDatabase.SearchCharacter(possessionCharacters[i].type); // キャラクターの初期データを取得
		if (data)
		{
			playerCharacters[i].type = data->type; // キャラクターの種類を設定
			playerCharacters[i].level = possessionCharacters[i].level; // レベルを設定
			int level = possessionCharacters[i].level; // レベルを取得
			playerCharacters[i].currentHp = (data->maxHp)+(level*10); // 初期HPを設定
			playerCharacters[i].maxHp = (data->maxHp)+(level*10); // 最大HPを設定
			playerCharacters[i].atk = (data->atk)+(level*2); // 攻撃力を設定
			playerCharacters[i].spd = (data->spd)+(level*1); // 速度を設定
			
		}
	}
}

//CharacteManagerでキャラクターの情報を取得するための関数
const std::vector<CharacterStatus>& PlayerStatusInitializer::GetPlayerCharacters() const
{ 
	return playerCharacters; 
}