#include "Game/Player/Player.h"
#include "Game/Player/PlayerMove.h"
#include "Game/GameConfig.h"
#include "Game/Turn/TurnManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/PlayerActionManager.h"

//PlayerMove playerMove;
//extern TurnManager turnManager;
//
//extern EnemyActionManager enemyActionManager;
//
//extern PlayerActionManager playerActionManager;

bool Player::Initialize(CharacterStatus status,StartPos startPos)
{
    if (!sprite.Init(
        g_device,
        status.spritePath.c_str()))
    {
        return false;
    }

    //初期化
	startX = startPos.startx;
	startY = startPos.starty;


    //playerTextureが示してる画像の情報を取得して構造体に入れる
    imageInfo = sprite.GetImageInfo();
    //画面サイズに合わせてスケーリングするための倍率を計算
    scaleX = static_cast<float>(g_windowWidth) / static_cast<float>(imageInfo.Width) * 0.25f;
    scaleY = static_cast<float>(g_windowHeight) / static_cast<float>(imageInfo.Height) * 0.25f;
    playerMove.Initialize(
        startX,
		startY,   
        static_cast<float>(imageInfo.Width),
        static_cast<float>(imageInfo.Height),
        scaleX,
        scaleY
    
    );

    status.maxHp = GameConfig::PlayerHp;
    status.atk = GameConfig::PlayerDamage;
	status.spd = GameConfig::PlayerSpeed;
	playerStatus = status;

    return true;
}


bool Player::Update()
{
    playerMove.Update(
        scaleX,
        scaleY,
        static_cast<float>(imageInfo.Width),
        static_cast<float>(imageInfo.Height)
    );

    if (playerMove.isMoved)
    {
        //ターンエンド時にプレイヤーの移動フラグをリセットする
		return false;
        /*playerMove.isMoved = false;*/
    }
    return true;

}

void Player::Finalize()
{
    //// プレイヤーの終了処理をここに記述
    //if (playerTexture != nullptr)
    //{
    //    playerTexture->Release();
    //    playerTexture = nullptr;
    //}

    //if (playerSprite != nullptr)
    //{
    //    playerSprite->Release();
    //    playerSprite = nullptr;
    //}
}

void Player::OnLostDevice()
{
   /* if (playerSprite != nullptr)
    {
        playerSprite->OnLostDevice();
    }*/
}

void Player::OnResetDevice()
{
    /*if (playerSprite != nullptr)
    {
        playerSprite->OnResetDevice();
    }*/
}

float Player::GetScaleX() const
{
    return scaleX;
}

float Player::GetScaleY() const
{
    return scaleY;
}


void Player::GetCharacterStatus(CharacterStatus& status) const
{
	status = status;
}

const HitDetection& Player::GetHitDetection() const
{
        return playerMove.GetHitDetection();
}



bool& Player::GetPlayerMove()
{
    return playerMove.isMoved;
}

void Player::StartTurn()
{
    playerMove.ResetAction();
}