//DirectXやWindows APIを使えるようにする共通ヘッダー
#pragma once
#pragma region ヘッダ
#include <d3dx9.h>//WinAPI&DirectX用ヘッダ
#include <d3d9.h>
#include <dinput.h>//dinputヘッダ

//マクロ定数
#define WIN_W 640 //プレイ画面の幅
#define WIN_H 480 //プレイ画面の高さ
#pragma endregion


#pragma region 背景描画用
extern IDirect3D9* g_direct3D;
extern IDirect3DDevice9* g_device;

bool DirectXInitialize(HWND window);
void DrawBegin();
void DrawEnd();
void DirectXFinalize();
bool DirectXResize(int width, int height);
#pragma endregion

#pragma region 外部公開
extern HWND h_WIN;//プレイ中のウィンドウ
extern bool finish;//プレイ終了フラグ
#pragma endregion

