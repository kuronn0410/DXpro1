//インプットに関する処理を行うファイルです。

#include "Application/InputManager.h"
#include "Window/win.h"
#include "Input/Input.h"

#include "Scene/SceneManager.h"

extern SceneManager sceneManager; // シーンマネージャーのインスタンス

void InputManager::Update()
{
	InputUpdate();
	ScaleChange();
	InputSceneChange();
}


void InputManager::ScaleChange()
{
	bool current = (GetKey('1')) != 0;
	if (current && !previous)
	{
		largeWindow = !largeWindow;
		//もし大きかったら小サイズに戻す
		if (largeWindow)
		{
			win_resize(1280, 720);
		}
		else
		{
			win_resize(640, 480);
		}
	}

	previous = current;
}

void InputManager::InputSceneChange()
{
	bool current = (GetKey('Q')) != 0;
	if (current && !previousScene)
	{
		isBattleScene = !isBattleScene;
		if (isBattleScene)
		{
			sceneManager.ChangeScene(SceneType::Battle);
		}
		else
		{
			sceneManager.ChangeScene(SceneType::Home);
		}
	}

	previousScene = current;
}