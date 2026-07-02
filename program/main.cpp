//メインのループ処理

#pragma region ヘッダ
#include <Windows.h>
#include "win.h"
#include "input.h"

//ウィンドウ用メイン関数
int APIENTRY WinMain(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//break_point_true(1);
	window_initialize(hWnd); //ウィンドウ初期化
	window_create(hWnd, nCmdShow);//ウィンドウ作成
	//メッセージループ
	MSG msg;
	while (!finish)
	{
		InputUpdate();
		WindowUpdate();
	}

	return 0;//メッセージパラメタを返す
}

#pragma endregion