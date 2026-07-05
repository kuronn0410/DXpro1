//インプットに関する処理を行うファイルです。

#include "header\input.h"
#include <Windows.h>
#include "header\win.h"

static bool previous = false;
static bool largeWindow = false;

void InputUpdate()
{
	bool current = (GetAsyncKeyState('1') & 0x8000) != 0;
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

