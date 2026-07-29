#include "Party/UI/CharacterCompositionUI.h"
#include "Window/WindowState.h"
#include "DebugTools/Debug.h"


bool CharacterCompositionUI::Initialize(CharacterManager& manager)
{
	// キャラクター編成
	characterManager = &manager;
	characters = characterManager->GetAllCharacters();
	// キャラクター編成UIの初期化処理をここに記述
	TotalCharacterNumber = characters.size();
	for(int i = 0; i < characters.size(); ++i)
	{
		float buttonPosX =20.0f +(i % 5) * 120.0f; // 横方向の位置を計算 (g_windowWidth - 00.0f) / 2.0f
		float buttonPosY = g_windowHeight * 0.1f + (i/ 5) * 100.0f; // 縦方向の位置を計算

		bool result = characterButton[i].Initialize(
			g_device,
			characters[i].spritePath.c_str(),
			buttonPosX,
			buttonPosY,
			100.0f,
			100.0f
		);
		

		char buffer[512];

		sprintf_s(
			buffer,
			"Button[%d] path=%s result=%d pos=(%f, %f)",
			i,
			characters[i].spritePath.c_str(),
			result,
			buttonPosX,
			buttonPosY
		);

		Library::DebugTools::DebugLog(buffer);
		
	}

	return true;
}

void CharacterCompositionUI::Update()
{
	for(int i = 0; i < characters.size(); ++i)
	{
		// キャラクター編成UIの更新処理をここに記述
		characterButton[i].Update();
		if(characterButton[i].IsClicked())
		{
			if (partyCount < 4)
			{
				AddCharacterToParty(i);
			}
			
			
		}
	}


}

void CharacterCompositionUI::AddCharacterToParty(int characterIndex)
{
	if(characterManager)
	{
		characterManager->AddCharacterToParty(characterIndex);
		float buttonPosX = 130.0f + (partyCount % 4) * 100.0f; // 横方向の位置を計算 (g_windowWidth - 00.0f) / 2.0f
		float buttonPosY = g_windowHeight * 0.71f + (partyCount / 4) * 100.0f; // 縦方向の位置を計算
		bool result = partyButton[partyCount].Initialize(
			g_device,
			characters[characterIndex].spritePath.c_str(),
			buttonPosX,
			buttonPosY,
			80.0f,
			80.0f
		);
		partyCount++;
		
	}
}


void CharacterCompositionUI::Draw()
{
	for(int i = 0; i < characters.size(); ++i)
	{
		characterButton[i].Draw();
		// キャラクター編成UIの描画処理をここに記述
	}

	if (partyCount > 0)
	{
		for (int i = 0; i < partyCount; ++i)
		{
			partyButton[i].Draw();
		}
	}


}

void CharacterCompositionUI::Finalize()
{
	for(int i = 0; i < characters.size(); ++i)
	{
		characterButton[i].Finalize();
	}
	characters.clear();
	TotalCharacterNumber = 0;
}