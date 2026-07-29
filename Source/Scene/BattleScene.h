#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"    
#include "UI/Button/Button.h"

class SceneManager;

class BattleScene : public IScene
{
public:
	BattleScene(SceneManager& sceneManager) : sceneManager(sceneManager) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	SceneManager& sceneManager;
	Background background;
};