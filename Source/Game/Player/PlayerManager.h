#pragma once
#include "Game/Player/Player.h"
class PlayerManager
{
public: 
	bool Init();
	void Update();
	void Finalize();
private:
	Player player[4];
};