#include "Game/Player/PlayerManager.h"

bool PlayerManager:: Init(const CharacterStatus* characterStatus, int partyCount)
{
	if (characterStatus == nullptr)
	{
		return false;
	}
	playerCount = partyCount;


	for(int i = 0; i < playerCount; i++)
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
	if (CheckAnnihilation())
	{
		isAnnihilation = true;	
		return false;
	}
	for(int i = 0; i < playerCount; i++)
	{
		if (i == moveIndex)
		{
			if(!player[i].GetIsAlive())
			{
				return false;
			}

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
	for(int i = 0; i < playerCount; i++)
	{
		if (!player[i].GetIsAlive())
		{
			continue;
		}
		player[i].Draw();
		
	}
}

void PlayerManager::Finalize()
{
	for(int i = 0; i < playerCount; i++)
	{
		player[i].Finalize();
	}
}


/*-----Žæ“¾-----*/
const HitDetection& PlayerManager::GetHitDetection(int Index) const
{
	return player[Index].GetHitDetection();
}

const int PlayerManager::GetPlayerCount() const
{
	return playerCount;
}

int PlayerManager::GetAttack(int Index) const
{
	return player[Index].GetAttack();
}

bool PlayerManager::GetAnnihilation() const
{
	return isAnnihilation;
}

/*-----ŽwŽ¦‚ÌŽó•t-----*/
void PlayerManager::StartTurn()
{
	for (int i = 0; i < 4; i++)
	{
		player[i].StartTurn();
	}
}

void PlayerManager::PlayerSelectTurn(int Index)
{
	moveIndex = Index;
}

void PlayerManager::TakeDamage(int Index, int damage)
{
	player[Index].TakeDamage(damage);
}

/*--‚»‚Ì‘¼--*/
bool PlayerManager::CheckAnnihilation() const
{
	for (int i = 0; i < playerCount; ++i)
	{
		if (player[i].GetIsAlive())
		{
			return false;
		}
	}

	return true;
}