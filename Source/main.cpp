//メインのループ処理

#pragma region ヘッダ
#include <Windows.h>
#include "Window/win.h"
#include "Application/InputManager.h"
#include "Graphics/dx2.h"
#include "Application/initialize.h"
//#include "Game/GameMain.h"
#include "Application/Finalize.h"
#include "Graphics/Font/Font.h"
#include "Scene/SceneManager.h"

/*
mainの関数
WindowsとGameの更新処理を呼び出す
*/

SceneManager sceneManager; // シーンマネージャーのインスタンス
InputManager inputManager; // インプットマネージャーのインスタンス
Font font; // フォントオブジェクトのインスタンス

void Update()
{
	WindowUpdate();
	//GameUpdate();
	sceneManager.Update();
}

void Draw()
{
	DrawBegin();
	//GameDraw();
	sceneManager.Draw();
	font.Draw("STAGE 1", 10, 10); // フォント描画の例
	
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
		inputManager.Update();
		Update();
		Draw();
	}
	
	finalize();

	return 0;//メッセージパラメタを返す
}


#pragma endregion