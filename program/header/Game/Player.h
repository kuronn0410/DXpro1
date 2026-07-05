#pragma once

extern float scaleX;
extern float scaleY;

bool player_initialize();
void player_update();
void player_draw();
void player_finalize();

void PlayerOnLostDevice();
void PlayerOnResetDevice();
