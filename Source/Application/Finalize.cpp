#include "Game/Player/Player.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"
#include "Game/GameMain.h"

extern Player player; // プレイヤーオブジェクトのインスタンス

void finalize()
{
	GameFinalize();
	BackgroundFinalize();
	DirectXFinalize();
}