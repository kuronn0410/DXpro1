#pragma once
#include "Game/Player/Player.h"
#include "Party/CharacterStatus.h"
#include "Game/StartPos.h"
#include "Game/Collision/HitDetection.h"
#include <vector>

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

	/*-----取得、指示の受付-----*/
	void StartTurn();
	void PlayerSelectTurn(int Index);
	const HitDetection& GetHitDetection(int Index) const;
	const int GetPlayerCount() const; // プレイヤーの数を取得する関数	
	int GetAttack(int Index) const; // 指定したプレイヤーの攻撃力を取得する関数
private:

	//出撃するキャラクター
	Player player[4];
	//パーティーに編成されたキャラクターのデータの構造体
	CharacterStatus playerStatus[4];
	int moveIndex = 0; //動かすキャラクターのインデックスを管理する変数
	StartPos startpos[4] = {
	{ 100.0f, 300.0f },
	{ 200.0f, 300.0f },
	{ 300.0f, 300.0f },
	{ 400.0f, 300.0f }
	};
	
};