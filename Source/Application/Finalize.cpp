#include "Game/Player/Player.h"
#include "Graphics/background.h"
#include "Graphics/dx2.h"

extern Player player; // プレイヤーオブジェクトのインスタンス

void finalize()
{
	player.Finalize();
	BackgroundFinalize();
	DirectXFinalize();
}