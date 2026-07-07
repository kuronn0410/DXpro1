#include "header/Game/GameMain.h"
#include "header/Game/Player.h"	


void game_initialize()
{
	// ƒQ[ƒ€‚Ì‰Šú‰»ˆ—‚ğ‚±‚±‚É‹Lq
	player_initialize();
}

void game_main()
{
	player_update();
}