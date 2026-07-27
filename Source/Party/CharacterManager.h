#pragma once

class CharacterManager
{
public:
	bool Init();
	void Update();
	void Finalize();
private:
	List<CharacterStatus> characters;
};