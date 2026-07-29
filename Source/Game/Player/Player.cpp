#include "Game/Player/Player.h"
#include "Game/Player/PlayerMove.h"
#include "Game/GameConfig.h"
#include "Game/Turn/TurnManager.h"
#include "Game/Turn/EnemyActionManager.h"
#include "Game/Turn/PlayerActionManager.h"

//PlayerMove playerMove;
extern TurnManager turnManager;

extern EnemyActionManager enemyActionManager;

extern PlayerActionManager playerActionManager;

bool Player::Initialize()
{
    if (!sprite.Init(
        g_device,
        "Assets\\Textures\\soccer.png"))
    {
        return false;
    }

    //初期化
	startX = GameConfig::PlayerStartX;
	startY = GameConfig::PlayerStartY;


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

    playerStatus.maxHp = GameConfig::PlayerHp;
    playerStatus.atk = GameConfig::PlayerDamage;
	playerStatus.spd = GameConfig::PlayerSpeed;

    return true;
}


void Player::Update()
{
    playerMove.Update(
        scaleX,
        scaleY,
        static_cast<float>(imageInfo.Width),
        static_cast<float>(imageInfo.Height)
    );

    if (playerMove.isMoved)
    {
     
		playerActionManager.SetActionState(ActionState::End);
        turnManager.SetTurnState(TurnState::EnemyAction);
        //ターンエンド時にプレイヤーの移動フラグをリセットする
        playerMove.isMoved = false;
        // 状態変更
        enemyActionManager.SetActionState(EnemyActionState::Move);
    }

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
	status = playerStatus;
}

const HitDetection& Player::GetHitDetection() const
{
        return playerMove.GetHitDetection();
}



bool& Player::GetPlayerMove()
{
    return playerMove.isMoved;
}