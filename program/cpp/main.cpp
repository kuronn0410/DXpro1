//メインのループ処理

#pragma region ヘッダ
#include <Windows.h>
#include "header\win.h"
#include "header\InputManager.h"
#include "header\background.h"
#include "header\Graphics\dx2.h"
#include "header\initialize.h"
#include "header/Game/Player.h"
#include "header/Game/GameMain.h"
#include "header\Finalize.h"


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