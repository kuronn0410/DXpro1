#include "Scene/HomeScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"

extern SceneManager sceneManager;

bool HomeScene::Initialize() 
{
	background.Initialize("Assets\\Textures\\Home.png");
	startButton.Initialize(
		g_device,
		"Assets\\Textures\\GameStartButton.png",
		(g_windowWidth - 200.0f) / 2.0f, // Center the button horizontally
		g_windowHeight * 0.7f,          // Position the button at 70% of the window height
		200.0f,                         // Button width
		100.0f                          // Button height
	);
	return true;
}
void HomeScene::Update()
{
	startButton.Update();
	if (startButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Battle);
	}
		// Update logic for the Home Scene
}
void HomeScene::Draw()
{
	
	background.Draw();
	startButton.Draw();
		// Draw the Home Scene
}
void HomeScene::Finalize() 
{
	background.Finalize();
	startButton.Finalize();
		// Clean up resources for the Home Scene
}