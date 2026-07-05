//メインのループ処理

#pragma region ヘッダ
#include <Windows.h>
#include "header\win.h"
#include "header\input.h"
#include "header\background.h"
#include "header\dx2.h"
#include "header\initialize.h"
#include "header/Game/Player.h"
#include "header/Game/GameMain.h"
#include "header/TimeManager.h"

//ウィンドウ用メイン関数
int APIENTRY WinMain(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Time::Init();
	// 初期化処理
	initialize(hWnd, hPrevInstance, lpCmdLine, nCmdShow);
	
	//メッセージループ
	MSG msg;
	while (!finish)
	{
		Time::Update();
		InputUpdate();
		WindowUpdate();
		DrawBegin();
		BackgroundDraw();
		game_main();
		DrawEnd();
	}
	
	player_finalize();
	BackgroundFinalize();
	DirectXFinalize();

	return 0;//メッセージパラメタを返す
}

#pragma endregion