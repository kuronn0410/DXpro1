#pragma region ヘッダ
#include "dx2.h"
#include "help1.h"
#include "win.h"
#include "main.h"
#include <Windows.h>
#pragma endregion


#pragma region ウィンドウ静的定義
HWND h_WIN = NULL;//プレイ中のウィンドウ
const char* WIN_TITLE = "CGプログラミング";//ウィンドウバーのタイトル
bool finish = false;//プレイ終了フラグ
#pragma endregion


#pragma region ウィンドウ関数定義

void WindowUpdate()
{
	MSG msg = {};

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			finish = true;
			return;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


//イベント処理関数
LRESULT CALLBACK window_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)//渡されたメッセージから，イベントの種類を解析する
	{
	case WM_DESTROY:   //ウィンドウ破壊された
		finish = true; //終了フラグを立てる
	}
	return DefWindowProc(hWnd, message, wParam, lParam);//デフォルトの処理
}

//ウインドウ初期化関数
void window_initialize(HINSTANCE hWnd)
{
	WNDCLASSEX wc;//ウィンドウ構造体

	ZeroMemory(&wc, sizeof(wc));//構造体をゼロで初期化

	wc.cbSize = sizeof(WNDCLASSEX);//構造体のサイズ
	wc.style = CS_HREDRAW | CS_VREDRAW;//ウィンドウが重なったら再描画する
	wc.lpfnWndProc = window_proc;//ウィンドウイベント処理関数の指定
	wc.hInstance = hWnd;//プレイするウインドウの指定
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//マウスポインタは標準
	wc.lpszMenuName = NULL;//ウィンドウにつけるメニューはなし
	wc.lpszClassName = WIN_TITLE;//ウィンドウバーのタイトル

	break_point_false(RegisterClassEx(&wc));//ウィンドウを登録する
}

//ウインドウ作成関数
void window_create(HINSTANCE hWin, int nCmdShow) 
{
	DWORD style = WS_OVERLAPPEDWINDOW;//ウィンドウは標準のスタイル

	RECT rec = { 0, 0, WIN_W, WIN_H };//プレイ画面サイズ 
	AdjustWindowRect(&rec, style, FALSE);//ウィンドウサイズ

	//ウィンドウの生成
	h_WIN = CreateWindow(WIN_TITLE, WIN_TITLE, style, CW_USEDEFAULT, CW_USEDEFAULT,
		rec.right - rec.left, rec.bottom - rec.top, NULL, NULL, hWin, NULL);
	break_point_false(h_WIN);

	//ウィンドウの表示・更新
	ShowWindow(h_WIN, nCmdShow);//ウィンドウを表示
	UpdateWindow(h_WIN);//ウィンドウを更新
}

void win_resize(int width, int height)
{
	RECT rec = { 0, 0, width, height };//プレイ画面サイズ 
	DWORD style = WS_OVERLAPPEDWINDOW;//ウィンドウは標準のスタイル
	AdjustWindowRect(&rec, style, FALSE);//ウィンドウサイズ
	SetWindowPos(h_WIN, NULL, 0, 0, rec.right - rec.left, rec.bottom - rec.top, SWP_NOMOVE | SWP_NOZORDER);
}

#pragma endregion
