#pragma region ヘッダ
#include "header\Graphics\dx2.h"
#include "header\help1.h"
#include "header\win.h"
#include "header\main.h"
#include <Windows.h>
#include "header/Game/Player.h"
#include "header\WindowState.h"//ウィンドウの状態を保持する変数
#include "header\background.h"
#pragma endregion

extern Player player; // プレイヤーオブジェクトのインスタンス

#pragma region ウィンドウ静的定義
HWND h_WIN = NULL;//プレイ中のウィンドウ
const char* WIN_TITLE = "CGプログラミング";//ウィンドウバーのタイトル
bool finish = false;//プレイ終了フラグ
#pragma endregion


#pragma region ウィンドウ関数定義

void WindowInitialize(HINSTANCE hWnd)
{
	window_initialize(hWnd);
	window_create(hWnd, SW_SHOW);
}

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
		case WM_SIZE:
			// 最小化中は幅・高さが0になるので更新しない
			// ウィンドウサイズが変更されたときの処理
			if (wParam != SIZE_MINIMIZED)
			{
				g_windowWidth = LOWORD(lParam);
				g_windowHeight = HIWORD(lParam);
				BackgroundOnLostDevice();
				player.OnLostDevice();

				if (DirectXResize(g_windowWidth, g_windowHeight))
				{
					BackgroundOnResetDevice();
					player.OnResetDevice();
				}
			}
			return 0;
		case WM_DESTROY:   //ウィンドウ破壊された
			finish = true; //終了フラグを立てる
			return 0;
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

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 白背景
	wc.lpszMenuName = NULL;

	break_point_false(RegisterClassEx(&wc));//ウィンドウを登録する
}

//ウインドウ作成関数
void window_create(HINSTANCE hWin, int nCmdShow) 
{
	DWORD style = WS_OVERLAPPEDWINDOW;//ウィンドウは標準のスタイル

	RECT rec = { 0, 0, g_windowWidth, g_windowHeight };//プレイ画面サイズ 
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
	RECT rec = { 0, 0, width, height };//プレイ画面サイズ {left,top,right,bottom};

	g_windowWidth = width;
	g_windowHeight = height;

	DWORD style = WS_OVERLAPPEDWINDOW;//ウィンドウは標準のスタイル
	AdjustWindowRect(&rec, style, FALSE);//ウィンドウサイズ
	// ウィンドウのサイズを変更(API)ウィンドウの現在位置と重なり順は維持し、サイズだけ変更する
	SetWindowPos(
		h_WIN,//変更対象のウィンドウ
		NULL,
		0, 0,//新しいウィンドウ位置のX座標とY座標
		rec.right - rec.left,//幅
		rec.bottom - rec.top,//高さ
		SWP_NOMOVE | SWP_NOZORDER//変更方法を指定する
		/*SWP_NOMOVE：ウィンドウ位置を変えない
		SWP_NOZORDER：ほかのウィンドウとの重なり順を変えない*/
	);

	InvalidateRect(h_WIN, NULL, TRUE);
	UpdateWindow(h_WIN);
}

#pragma endregion
