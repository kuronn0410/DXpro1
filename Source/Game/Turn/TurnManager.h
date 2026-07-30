#pragma once
//#include "Game/Turn/PlayerActionManager.h"
//#include "Game/Turn/EnemyActionManager.h"
//#include "Game/Player/PlayerManager.h"

//1ターン内の状態を管理する列挙型
enum class TurnState
{
    TurnStart,
    PlayerSelect,
    PlayerAction,
    EnemyAction,
    TurnEnd
};


class TurnManager
{
public:
    void SetTurnState(TurnState state);
    // 状態変更
	const TurnState& GetTurnState() const;
    // ターン管理クラス
    /*int currentTurn = 0;*/

    //プレーヤーのアクションフェーズの流れを管理する
   
    //現在のターンを進める関数
   /* void UpdateTurn(PlayerManager& playerManager);*/
    // 状態変更
    // 現在のターン状態
    
   
private:
    TurnState currentTurnState;
	/*PlayerActionManager playerActionManager;
	EnemyActionManager enemyActionManager;*/

};

