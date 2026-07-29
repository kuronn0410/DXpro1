#include "Scene/RewardScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"

bool RewardScene::Initialize()
{
	background.Initialize("Assets\\Textures\\Reward.png");
	backSceneButton.Initialize(
		g_device,
		"Assets\\Textures\\BackButton.png",
		(g_windowWidth) / 2.0f + 280.0f,  // Position the button at the top-left corner
		g_windowHeight * 0.03f,  // Position the button at the top-left corner
		30.0f, // Button width
		30.0f   // Button height
	);

	return true;
}

void RewardScene::Update()
{
	backSceneButton.Update();

	if (backSceneButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Home);
	}
}

void RewardScene::Draw()
{
	background.Draw();
	backSceneButton.Draw();
}

void RewardScene::Finalize()
{
	background.Finalize();
	backSceneButton.Finalize();
}