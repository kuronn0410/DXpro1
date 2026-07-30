#pragma once
#include "Game/Player/Player.h"
#include "Party/CharacterStatus.h"
#include "Game/StartPos.h"

#include "Game/Turn/TurnManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/PlayerActionManager.h"
/*
必要な情報、画像、ステータス
*/
class PlayerManager
{
public: 
	bool Init(const CharacterStatus* characterStatuses);
	/// <summary>
	/// 全プレーヤーの更新処理
	/// </summary>
	/// <returns>動いてない間はtrueを返す/動いたらfalseを返す</returns>
	bool Update();
	void Draw();
	void Finalize();
	void StartTurn();
private:

	//出撃するキャラクター
	Player player[4];
	//パーティーに編成されたキャラクターのデータの構造体
	CharacterStatus playerStatus[4];

	StartPos startpos[4] = {
	{ 100.0f, 300.0f },
	{ 200.0f, 300.0f },
	{ 300.0f, 300.0f },
	{ 400.0f, 300.0f }
	};
	
};