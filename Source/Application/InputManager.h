//input.h
#pragma once


class InputManager
{
public:
	void Update();
	
private:
	void ScaleChange();
	void ChangeState();
	bool previous = false;
	bool largeWindow = false;
	bool playerTurn = false;
	bool previousTurn = false;
};
