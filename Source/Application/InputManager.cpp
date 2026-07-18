//インプットに関する処理を行うファイルです。

#include "Application/InputManager.h"
#include "Window/win.h"
#include "Input/Input.h"

void InputManager::Update()
{
	InputUpdate();
	ScaleChange();
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
