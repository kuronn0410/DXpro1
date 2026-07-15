#include "Game/Player/Player.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Game/GameMain.h"

extern Player player; // プレイヤーオブジェクトのインスタンス
extern Background background; // 背景オブジェクトのインスタンス
void finalize()
{
	GameFinalize();
	background.Finalize();
	DirectXFinalize();
}