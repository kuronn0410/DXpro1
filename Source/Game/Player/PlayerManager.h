#pragma once
#include "Game/Player/Player.h"
/*
必要な情報、画像、ステータス
*/
class PlayerManager
{
public: 
	bool Init();
	void Update();
	void Finalize();
private:
	Player player[4];
};