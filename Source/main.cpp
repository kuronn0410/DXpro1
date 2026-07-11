//メインのループ処理

#pragma region ヘッダ
#include <Windows.h>
#include "Window/win.h"
#include "Application/InputManager.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Application/initialize.h"
#include "Game/GameMain.h"
#include "Application/Finalize.h"

/*
mainの関数
WindowsとGameの更新処理を呼び出す
*/

void Update()
{
	DrawBegin();
	WindowUpdate();
	GameUpdate();
}

void Draw()
{
	// 描画の更新処理をここに記述
	BackgroundDraw();
	GameDraw();
	DrawEnd();
}

//ウィンドウ用メイン関数
int APIENTRY WinMain(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// 初期化処理
	initialize(hWnd, hPrevInstance, lpCmdLine, nCmdShow);
	
	//メッセージループ
	MSG msg;
	while (!finish)
	{
		InputManagerUpdate();
		Update();
		Draw();
	}
	
	finalize();

	return 0;//メッセージパラメタを返す
}


#pragma endregion