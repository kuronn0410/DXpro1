//input.h
#pragma once


class InputManager
{
public:
	void InputManagerUpdate();
	
private:
	void ScaleChange();
	void ChangeState();
	bool previous = false;
	bool largeWindow = false;
	bool playerTurn = false;
	bool previousTurn = false;
};
