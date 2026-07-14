//インプットに関する処理を行うファイルです。

#include "Application/InputManager.h"
#include <Windows.h>
#include "Window/win.h"
#include "Input/Input.h"
#include "Game/Turn/TurnManager.h"
#include "Game/Player/PlayerMove.h"
#include "Game/Turn/PlayerActionManager.h"


extern TurnManager turnManager; // ターン管理オブジェクトのインスタンス
extern PlayerMove playerMove; // プレイヤーの移動管理オブジェクトのインスタンス
extern PlayerActionManager playerActionManager; // プレイヤーの行動管理オブジェクトのインスタンス
void InputManager::Update()
{
	InputUpdate();
	ScaleChange();
	ChangeState();
}


void InputManager::ScaleChange()
{
	bool current = (GetKey('1')) != 0;
	if (current && !previous)
	{
		largeWindow = !largeWindow;
		//もし大きかったら小サイズに戻す
		if (largeWindow)
		{
			win_resize(1280, 720);
		}
		else
		{
			win_resize(640, 480);
		}
	}

	previous = current;
}

void InputManager::ChangeState()
{
	bool currentTurn = (GetKey('2')) != 0;
	if (currentTurn && !previousTurn)
	{
		playerTurn = !playerTurn;
		//もし大きかったら小サイズに戻す
		if (playerTurn)
		{
			turnManager.SetTurnState(TurnState::PlayerAction);
			// 状態変更
			playerActionManager.SetActionState(ActionState::Move);
			
		}
	}

	previousTurn = currentTurn;
}
