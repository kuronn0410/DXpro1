#include "Game/Player/Player.h"

#include "Game/Player/PlayerMove.h"


void Player::Draw()
{

    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.16f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.2f;

    sprite.Draw(playerMove.player_x, playerMove.player_y, scaleX, scaleY);
}