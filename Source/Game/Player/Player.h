#pragma once
#include "Graphics/dx2.h"
#include "Window/WindowState.h"
#include "Game/Collision/HitDetection.h"
#include "Graphics/Sprite/Sprite.h"
#include "Party/CharacterStatus.h"
#include "Game/Player/PlayerMove.h"
#include "Party/CharacterStatus.h"
#include "Game/StartPos.h"

// Player.h
class Player
{
public:
    
    bool Initialize(CharacterStatus status, StartPos startPos);
    bool Update();
    void Draw();
    void Finalize();

    //Spriteの解除
    void OnLostDevice();
    void OnResetDevice();

    /*-----取得、指示の受付-----*/
    //スケールを外部から取得するための関数
    float GetScaleX() const;
    float GetScaleY() const;
    void GetCharacterStatus(CharacterStatus& status) const;
    const HitDetection& GetHitDetection() const;
    void PlayerSelectTurn(bool state);
    void StartTurn();

private:
    

    ////所持するオブジェクト
    //IDirect3DTexture9* playerTexture = nullptr;
    //ID3DXSprite* playerSprite = nullptr;
    Library::Graphics::Sprite sprite;
    CharacterStatus playerStatus{};  
	PlayerMove playerMove;
    D3DSURFACE_DESC imageInfo = {};

    //ゲーム開始時のポジションを保存する引数
    float startX = 0.0f;
	float startY = 0.0f;

    //画面のスケールに合わせたPlayerのスケール
    float scaleX = 0.0f;
    float scaleY = 0.0f;
   
};