#include "TurnEnd.h"
#include "Game/Turn/TurnManager.h"
//デバック用
#include <Windows.h>
#include <cstdio>

extern TurnManager turnManager; // ターン管理オブジェクトのインスタンス
/*
敵が生きてるかどうかを確認してターンを進める
*/

void TurnEndCheck()
{
	
	turnManager.currentTurn++;
	// デバッグ用に現在のターン数を出力
	char buffer[128];
	sprintf_s(
		buffer,
		sizeof(buffer),
		"currentTurn = %d\n",
		turnManager.currentTurn
	);
	OutputDebugStringA(buffer);
	turnManager.SetTurnState(TurnState::TurnStart);

}