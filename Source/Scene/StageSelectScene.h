#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
class SceneManager;
class EnemyStatusInitializer;

class StageSelectScene : public IScene
{
public:
    StageSelectScene(
        SceneManager& sceneManager, 
        EnemyStatusInitializer& enemyStatusInitializer) : 
        sceneManager(sceneManager), 
        enemyStatusInitializer(enemyStatusInitializer) {};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
    SceneManager& sceneManager;
	EnemyStatusInitializer& enemyStatusInitializer;
    Background background;
	//Button stageButton[3];
	Button startButton;
    Button backSceneButton;
	Button stage1Button;
	Button stage2Button;
};