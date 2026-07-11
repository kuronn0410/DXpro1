#pragma once

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
   
    // ターン管理クラス
    int currentTurn = 0;

    //プレーヤーのアクションフェーズの流れを管理する
   
    //現在のターンを進める関数
    void UpdateTurn();
    // 状態変更
    // 現在のターン状態
    TurnState currentTurnState;
   
private:
   

};

