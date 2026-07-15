
#pragma once
#include "Graphics/Sprite/Sprite.h"

class Background
{
public:
	bool Initialize();
	void Draw();
	void Finalize();

	void OnLostDevice();
	void OnResetDevice();
private:
	Library::Graphics::Sprite sprite;
	IDirect3DTexture9* backgroundTexture = nullptr;
	D3DSURFACE_DESC imageInfo = {};
	float scaleX =0.0f;
	float scaleY =0.0f;	
};