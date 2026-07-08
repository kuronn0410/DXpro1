//インプットに関する処理を行うファイルです。

#include "header\InputManager.h"
#include <Windows.h>
#include "header\win.h"
#include "Library\Input\Input.h"

static bool previous = false;
static bool largeWindow = false;

void InputManagerUpdate()
{
	InputUpdate();
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

