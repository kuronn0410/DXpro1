#pragma once
#include "Graphics/dx2.h"
#include "Window/WindowState.h"
#include "Game/Collision/HitDetection.h"
#include "Graphics/Sprite/Sprite.h"

// Player.h
class Player
{
public:
    bool Initialize();
    void Update();
    void Draw();
    void Finalize();

    void OnLostDevice();
    void OnResetDevice();

    float GetScaleX() const;
    float GetScaleY() const;
     float centerX = 0.0f;
    float centerY = 0.0f;
    //ç\ë¢ëÃÇÃópà”
    float scaleX = 0.0f;
    float scaleY = 0.0f;
    D3DSURFACE_DESC imageInfo = {};

private:
    
    IDirect3DTexture9* playerTexture = nullptr;
    ID3DXSprite* playerSprite = nullptr;
    Library::Graphics::Sprite sprite;
   
};