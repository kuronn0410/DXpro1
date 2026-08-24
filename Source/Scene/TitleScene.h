#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
class SceneManager;

class TitleScene : public IScene
{
public:
    TitleScene(SceneManager& sceneManager) :sceneManager(sceneManager) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
    SceneManager& sceneManager;
    Background background;
    //Button stageButton[3];
    Button startButton;
};