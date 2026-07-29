#pragma once
#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
#include "Party/UI/CharacterCompositionUI.h"
#include "Party/CharacterManager.h"

class SceneManager;
class CharacterManager;

class PartySelectScene : public IScene
{
public:
	PartySelectScene(SceneManager& sceneManager, CharacterManager& characterManager) 
		: sceneManager(sceneManager), characterManager(characterManager) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;

	const CharacterManager& GetCharacterManager() const { return characterManager; }
private:
	Background background;
	Button PartyButton[4];
    SceneManager& sceneManager;
	Button backSceneButton;
	CharacterManager& characterManager;
    CharacterCompositionUI characterCompositionUI;
};