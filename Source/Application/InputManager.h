//input.h
#pragma once


class InputManager
{
public:
	void Update();
	
private:
	void ScaleChange();
	void InputSceneChange();
	bool previous = false;
	bool largeWindow = false;

	bool isBattleScene = false;
	bool previousScene = false;
};
