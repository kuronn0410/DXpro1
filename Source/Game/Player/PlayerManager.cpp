#include "Game/Player/PlayerManager.h"

bool PlayerManager:: Init()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].Initialize();
	}
	return true;
}

void PlayerManager::Update()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].Update();
	}
}

void PlayerManager::Finalize()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].Finalize();
	}
}

