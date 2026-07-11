
#pragma region ヘッダ
#include <Windows.h>
#include "Window/win.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Game/Player/Player.h"
#include "Game/GameMain.h"
#include "Application/initialize.h"

extern Player player; // プレイヤーオブジェクトのインスタンス

int initialize(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//break_point_true(1);
	WindowInitialize(hWnd);
	//DirectXをWindowsに描画できるように初期化して接続
	if (!DirectXInitialize(h_WIN))
	{
		return -1;
	}

	if (!BackgroundInitialize())
	{
		return -1;
	}
	player.Initialize();
	return 0;

	GameInitialize();
}