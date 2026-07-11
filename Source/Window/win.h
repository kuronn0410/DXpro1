
// win.h
#pragma once
#include <Windows.h>
LRESULT CALLBACK window_proc(
	HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);//イベント処理関数
//ウインドウ更新関数
void WindowUpdate();
//ウインドウ初期化関数
void window_initialize(HINSTANCE hWnd);
//ウインドウ作成関数
void window_create(HINSTANCE hWin, int nCmdShow);
//ウィンドウサイズ変更関数
void win_resize(int width, int height);

void WindowInitialize(HINSTANCE hWnd);
extern bool finish;