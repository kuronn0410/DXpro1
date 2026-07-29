#include "Game/Player/Player.h"
//#include "Graphics/background.h"
#include "Graphics/dx2.h"
//#include "Game/GameMain.h"
#include "Scene/SceneManager.h"

extern Player player; // プレイヤーオブジェクトのインスタンス
void finalize(SceneManager& sceneManager)
{
	sceneManager.Finalize();
	DirectXFinalize();
}