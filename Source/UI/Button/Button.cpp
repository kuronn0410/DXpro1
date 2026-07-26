/*
spriteの描画(ボタン)
カーソルの取得
カーソルとボタンが重なってるかどうか判定する
左クリックされたかどうか判定する
発動する対象の関数を呼び出す
*/

#include "UI/Button/Button.h"

bool Button::Initialize(
	IDirect3DDevice9* g_device, 
	const char* filePath, 
	float posX, 
	float posY, 
	float width, 
	float height)
{
	buttonPosX = posX;
	buttonPosY = posY;
	buttonWidth = width;
	buttonHeight = height;

	if (!buttonSprite.Init(g_device, filePath))
	{
		return false;
	}
	imageInfo = buttonSprite.GetImageInfo();

	return true;
}
void Button::Update()
{
	
	if (GetCursorPos(&mousePoint))
	{
		ScreenToClient(h_WIN, &mousePoint);

		mouseX = mousePoint.x;
		mouseY = mousePoint.y;

		bool isHovered =
			mouseX >= buttonPosX &&
			mouseX < buttonPosX + buttonWidth &&
			mouseY >= buttonPosY &&
			mouseY < buttonPosY + buttonHeight;
		if (isHovered)
		{
			currentState = ButtonState::Hovered;
			if(GetKeyDown(VK_LBUTTON))
			{
				currentState = ButtonState::Clicked;

			}
		}
		else
		{
			currentState = ButtonState::Normal;
		}
	}

}
void Button::Draw()
{
	float scaleX =
		buttonWidth / static_cast<float>(imageInfo.Width);

	float scaleY =
		buttonHeight / static_cast<float>(imageInfo.Height);

	buttonSprite.Draw(
		buttonPosX,
		buttonPosY,
		scaleX,
		scaleY
	);
}

void Button::Finalize()
{
	buttonSprite.Release();
}

// ボタンがクリックされたかどうかを返す関数
bool Button::IsClicked() const
{
	return currentState == ButtonState::Clicked;
}
