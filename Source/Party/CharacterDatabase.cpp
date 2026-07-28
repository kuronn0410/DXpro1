#include "CharacterDatabase.h"

bool CharacterDatabase::Initialize()
{
	CreateCharacterDatabase();
	return true;
}

const CharacterData* CharacterDatabase::SearchCharacter(CharacterType type) const
{
	auto it = characterMap.find(type);
	if (it == characterMap.end())
	{
		return nullptr;
	}

	return &it->second;
}

void CharacterDatabase::CreateCharacterDatabase()
{
	for (int i = 0; i < 5; i++)
	{
		characterMap[datas[i].type] = datas[i];
	}
}