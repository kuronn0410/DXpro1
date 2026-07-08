
#pragma region ƒwƒbƒ_
#include <Windows.h>
#include "header\win.h"
#include "header\background.h"
#include "header\Graphics\dx2.h"
#include "header\Game/Player.h"
#include "header\Game/GameMain.h"
#include "header\initialize.h"



int initialize(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//break_point_true(1);
	WindowInitialize(hWnd);
	//DirectX‚ğWindows‚É•`‰æ‚Å‚«‚é‚æ‚¤‚É‰Šú‰»‚µ‚ÄÚ‘±
	if (!DirectXInitialize(h_WIN))
	{
		return -1;
	}

	if (!BackgroundInitialize())
	{
		return -1;
	}
	player_initialize();
	return 0;

	GameInitialize();
}