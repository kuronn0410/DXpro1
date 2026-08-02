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
#include "main.h"
/*
mainの関数
WindowsとGameの更新処理を呼び出す
*/


InputManager inputManager; // インプットマネージャーのインスタンス
Font font; // フォントオブジェクトのインスタンス



//ウィンドウ用メイン関数
int APIENTRY WinMain(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CharacterManager characterManager;
	EnemyStatusInitializer enemyStatusInitializer;
	SceneManager sceneManager(characterManager, enemyStatusInitializer); // シーンマネージャーのインスタンス
	
	// 初期化処理
	initialize(hWnd, hPrevInstance, lpCmdLine, nCmdShow, sceneManager);
	
	//メッセージループ
	MSG msg;
	while (!finish)
	{
		inputManager.Update();
		Update(sceneManager);
		Draw(sceneManager);
	}
	
	finalize(sceneManager);

	return 0;//メッセージパラメタを返す
}

void Update(SceneManager& sceneManager)
{
	WindowUpdate();
	//GameUpdate();
	sceneManager.Update();
}

void Draw(SceneManager& sceneManager)
{
	DrawBegin();
	//GameDraw();
	sceneManager.Draw();
	font.Draw("STAGE 1", 10, 10); // フォント描画の例
	DrawEnd();
}

#pragma endregion