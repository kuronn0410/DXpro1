#include "Game/Player/Player.h"

#include "Game/Player/PlayerMove.h"


extern PlayerMove playerMove;

void Player::Draw()
{
    // ƒvƒŒƒCƒ„[‚Ì•`‰æˆ—‚ğ‚±‚±‚É‹Lq
    // ”wŒi‚Ì•`‰æˆ—‚ğ‚±‚±‚É‹Lq
    if (playerSprite == nullptr ||
        playerTexture == nullptr)
    {
        return;
    }
    
	


    //Šg‘å—¦
    D3DXVECTOR2 scale(scaleX, scaleY);
	//ƒvƒŒƒCƒ„[‚ÌÀ•W‚ğ\‘¢‘Ì‚É“ü‚ê‚é
    D3DXVECTOR2 position(playerMove.player_x, playerMove.player_y);
    //ŒvZŒ‹‰Ê‚Ì•Û‘¶æ
    D3DXMATRIX Matrix;

    //
    D3DXMatrixTransformation2D(
		&Matrix,//ŒvZŒ‹‰Ê‚Ì•Û‘¶æƒAƒhƒŒƒX‚ğw’è
        nullptr,
        0.0f,
        &scale,
        nullptr,
        0.0f,
        &position
    );

    centerX = position.x + imageInfo.Width * scale.x * 0.5f;
    centerY = position.y + imageInfo.Height * scale.y * 0.5f;

    playerSprite->Begin(D3DXSPRITE_ALPHABLEND);
    playerSprite->SetTransform(&Matrix);

    playerSprite->Draw(
        playerTexture,
        nullptr,
        nullptr,
        nullptr,
        D3DCOLOR_XRGB(255, 255, 255)
    );

    playerSprite->End();
}