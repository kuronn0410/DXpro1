
#pragma region ヘッダ
#include <Windows.h>
#include "Window/win.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Graphics/Font/Font.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneType.h"


extern Background background; // 背景オブジェクトのインスタンス
extern Font font; // フォントオブジェクトのインスタンス
int initialize(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow, SceneManager& sceneManager)
{
	
	WindowInitialize(hWnd);
	//DirectXをWindowsに描画できるように初期化して接続
	if (!DirectXInitialize(h_WIN))
	{
		return -1;
	}
	sceneManager.Initialize(SceneType::Home); // 初期シーンをHomeに設定
	//GameInitialize();
	font.Init(g_device);
	return 0;
}