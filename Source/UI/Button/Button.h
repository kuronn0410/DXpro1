#pragma once
#include "Graphics/Sprite/Sprite.h"
#include <Windows.h>
#include "Graphics/dx2.h"
#include "Input/Input.h"	



class Button
{
public:
	bool Initialize(
		IDirect3DDevice9* g_device, 
		const char* filePath, 
		float posX, 
		float posY, 
		float width, 
		float height);
	void Update();
	void Draw();
	void Finalize();

	bool IsClicked() const;
private:
	//ボタンの状態を管理する変数
	enum class ButtonState
	{
		Normal,
		Hovered,
		Clicked
	};
	ButtonState currentState = ButtonState::Normal;
	bool isHovered = false;
		
	D3DSURFACE_DESC imageInfo{};

	//ボタンの位置とサイズ
	float buttonPosX = 0.0f;
	float buttonPosY = 0.0f;
	float buttonWidth = 100.0f;
	float buttonHeight = 50.0f;
	//ボタンの描画に使用するスプライトやテクスチャの情報
	Library::Graphics::Sprite buttonSprite;



	POINT mousePoint{};

	/*GetCursorPos(&mousePoint);
	ScreenToClient(h_WIN, &mousePoint);*/

	int mouseX = 0;
	int mouseY = 0;


};