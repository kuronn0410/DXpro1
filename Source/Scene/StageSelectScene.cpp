#include "Scene/StageSelectScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"
#include "DebugTools/Debug.h"


bool StageSelectScene::Initialize()
{
	background.Initialize("Assets\\Textures\\StageSelect.png");
	startButton.Initialize(
		g_device,
		"Assets\\Textures\\GameStartButton.png",
		(g_windowWidth - 200.0f) / 2.0f, 
		g_windowHeight * 0.7f,          
		200.0f,                         
		100.0f                        
	);

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
void StageSelectScene::Update()
{
	startButton.Update();
	if (startButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Battle);
	}

	if (backSceneButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Home);
	}

}
void StageSelectScene::Draw()
{

	background.Draw();
	startButton.Draw();
}
void StageSelectScene::Finalize()
{
	background.Finalize();
	startButton.Finalize();
}