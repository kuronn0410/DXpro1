#include "header/Game/Player.h"
#include "header\background.h"
#include "header\Graphics\dx2.h"

extern Player player; // プレイヤーオブジェクトのインスタンス

void finalize()
{
	player.Finalize();
	BackgroundFinalize();
	DirectXFinalize();
}