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

//PlayerAction内の状態を管理する列挙型
enum class ActionState
{
    None,
    Aim,
    Move,
    End
};


class TurnManager
{
public:
    void SetTurnState(TurnState state);
    // 状態変更
    void SetActionState(ActionState state);
    // ターン管理クラス
    int currentTurn;

    //プレーヤーのアクションフェーズの流れを管理する
    void UpdateAction();
    //現在のターンを進める関数
    void UpdateTurn();
    // 状態変更
    // 現在のターン状態
    TurnState currentTurnState;

    // 現在の行動状態
    ActionState currentActionState;
    
private:
   

};

