//DirectXやWindows APIを使えるようにする共通ヘッダー
#pragma once
#pragma region ヘッダ
#include <d3dx9.h>//WinAPI&DirectX用ヘッダ
#include <dinput.h>//dinputヘッダ

//マクロ定数
#define WIN_W 640 //プレイ画面の幅
#define WIN_H 480 //プレイ画面の高さ
#pragma endregion

#pragma region 外部公開
extern HWND h_WIN;//プレイ中のウィンドウ
extern bool finish;//プレイ終了フラグ
#pragma endregion

