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
		if (i == moveIndex)
		{
			player[i].PlayerSelectTurn(true);
			if (!player[i].Update())
			{
				return false;
			}
		}
		else
		{
			player[i].PlayerSelectTurn(false);

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


/*-----Žæ“¾AŽwŽ¦‚ÌŽó•t-----*/
void PlayerManager::StartTurn()
{
	for(int i = 0; i < 4; i++)
	{
		player[i].StartTurn();
	}
}

void PlayerManager::PlayerSelectTurn(int Index)
{
	moveIndex = Index;
}

const HitDetection& PlayerManager::GetHitDetection(int Index) const
{
	return player[Index].GetHitDetection();
}

const int PlayerManager::GetPlayerCount() const
{
	return 4;
}

int PlayerManager::GetAttack(int Index) const
{
	return player[Index].GetAttack();
}