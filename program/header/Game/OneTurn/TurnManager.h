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

// ターン管理クラス
extern int currentTurn;
// 現在のターン状態
extern TurnState currentTurnState;

// 現在の行動状態
extern ActionState currentActionState;

//プレーヤーのアクションフェーズの流れを管理する
void UpdateAction();
//現在のターンを進める関数
void UpdateTurn();
// 状態変更
void SetTurnState(TurnState state);
// 状態変更
void SetActionState(ActionState state);
