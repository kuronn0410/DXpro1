//インプットに関する処理を行うファイルです。

#include "Application/InputManager.h"
#include <Windows.h>
#include "Window/win.h"
#include "Input/Input.h"
#include "Game/Turn/TurnManager.h"


extern TurnManager turnManager; // ターン管理オブジェクトのインスタンス

void InputManager::InputManagerUpdate()
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
			turnManager.SetActionState(ActionState::Move);
			
		}
		else
		{
			turnManager.SetTurnState( TurnState::TurnStart);
			
			// 状態変更
			turnManager.SetActionState( ActionState::None);
			
		}
	}

	previousTurn = currentTurn;
}
