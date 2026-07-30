#include "Game/Player/PlayerManager.h"

bool PlayerManager:: Init(const CharacterStatus* characterStatus)
{
	if (characterStatus == nullptr)
	{
		return false;
	}


	for(int i = 0; i < 4; i++)
	{
		playerStatus[i] = characterStatus[i];
		
		if (!player[i].Initialize(playerStatus[i],startpos[i]))
		{
			return false;
		}
	}
	return true;
}

bool PlayerManager::Update()
{
	for(int i = 0; i < 4; i++)
	{
		if(!player[i].Update())
		{
			return false;
		}	
	}
	return true;
}

void PlayerManager::Draw()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].Draw();
	}
}

void PlayerManager::Finalize()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].Finalize();
	}
}

void PlayerManager::StartTurn()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].StartTurn();
	}
}

