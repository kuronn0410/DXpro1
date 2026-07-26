#include "Game/Player/Player.h"
//#include "Graphics/background.h"
#include "Graphics/dx2.h"
//#include "Game/GameMain.h"
#include "Scene/SceneManager.h"

extern Player player; // プレイヤーオブジェクトのインスタンス
//extern Background background; // 背景オブジェクトのインスタンス
extern SceneManager sceneManager; // シーンマネージャーのインスタンス
void finalize()
{
	//GameFinalize();
	sceneManager.Finalize();
	//background.Finalize();
	DirectXFinalize();
}