
#pragma region ƒwƒbƒ_
#include <Windows.h>
#include "Window/win.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Game/GameMain.h"
#include "Application/initialize.h"


int initialize(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	
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
	GameInitialize();
	return 0;
}