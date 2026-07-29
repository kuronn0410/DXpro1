#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
#include "Scene/SceneManager.h"

class SceneManager;

class RewardScene : public IScene
{
public:
	RewardScene(SceneManager& sceneManager) : sceneManager(sceneManager) {};
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
private:
	Background background;
	SceneManager& sceneManager;
	//Button rewardButton[3];
	Button backSceneButton;
};