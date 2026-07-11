//インプットに関する処理を行うファイルです。

#include "Application/InputManager.h"
#include <Windows.h>
#include "Window/win.h"
#include "Input/Input.h"
#include "Game/Turn/TurnManager.h"

static bool previous = false;
static bool largeWindow = false;
static bool playerTurn = false;
static bool previousTurn = false;

void InputManagerUpdate()
{
	InputUpdate();
	ScaleChange();
	ChangeState();
}


void ScaleChange()
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

void ChangeState()
{
	bool currentTurn = (GetKey('2')) != 0;
	if (currentTurn && !previousTurn)
	{
		playerTurn = !playerTurn;
		//もし大きかったら小サイズに戻す
		if (playerTurn)
		{
			SetTurnState(TurnState::PlayerAction);

			// 状態変更
			SetActionState(ActionState::Move);
			
		}
		else
		{
			SetTurnState( TurnState::TurnStart);
			
			// 状態変更
			SetActionState( ActionState::None);
			
		}
	}

	previousTurn = currentTurn;
}
