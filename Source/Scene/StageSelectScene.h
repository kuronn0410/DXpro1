#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
class SceneManager;

class StageSelectScene : public IScene
{
public:
    StageSelectScene(SceneManager& sceneManager) : sceneManager(sceneManager) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
    SceneManager& sceneManager;
    Background background;
	//Button stageButton[3];
	Button startButton;
    Button backSceneButton;
};