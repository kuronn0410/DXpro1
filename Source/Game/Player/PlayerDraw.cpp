#include "Game/Player/Player.h"

#include "Game/Player/PlayerMove.h"


extern PlayerMove playerMove;

void Player::Draw()
{

    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;

    sprite.Draw(playerMove.player_x, playerMove.player_y, scaleX, scaleY);
}