#include "TurnEnd.h"
#include "Game/Turn/TurnManager.h"
//デバック用
#include <Windows.h>
#include <cstdio>

extern TurnManager turnManager; // ターン管理オブジェクトのインスタンス
//そのターンの結果確認
//敵が残っているか
//ターン数を進める
//ステージクリア / 次ステージ判定

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
	//isTurnEnd = true;
	
}