//input.h
#pragma once


class InputManager
{
public:
	void Update();
	
private:
	void ScaleChange();
	bool previous = false;
	bool largeWindow = false;
};
