#include "header/Game/Player.h"
#include "header\background.h"
#include "header\Graphics\dx2.h"
void finalize()
{
	player_finalize();
	BackgroundFinalize();
	DirectXFinalize();
}