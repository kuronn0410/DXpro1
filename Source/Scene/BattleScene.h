#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"    
#include "UI/Button/Button.h"
#include "Game/GameMain.h"

class SceneManager;
class CharacterManager;

class BattleScene : public IScene
{
public:
	BattleScene(SceneManager& sceneManager, CharacterManager& characterManager)
		: sceneManager(sceneManager), characterManager(characterManager), gameMain(characterManager){};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	SceneManager& sceneManager;
	CharacterManager& characterManager;
	Background background;
	GameMain gameMain;

};