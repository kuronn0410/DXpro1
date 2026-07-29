#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
#include "Scene/SceneManager.h"

class SceneManager;

class HomeScene : public IScene
{
public:
    HomeScene(SceneManager& sceneManager) : sceneManager(sceneManager) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	Background background;
	Button stageSelectButton;
	Button partyCompositionButton;
    SceneManager& sceneManager;
    
};