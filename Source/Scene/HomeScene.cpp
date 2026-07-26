#include "Scene/HomeScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"
#include "DebugTools/Debug.h"

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

	partyCompositionButton.Initialize(
		g_device,
		"Assets\\Textures\\PartyComposition.png",
		(g_windowWidth - 200.0f) / 2.0f -80.0f, // Center the button horizontally
		g_windowHeight * 0.72f,         // Position the button at 70% of the window height
		80.0f,                         // Button width
		80.0f                          // Button height
	);

	
	return true;
}
void HomeScene::Update()
{
	startButton.Update();
	partyCompositionButton.Update();
	if (startButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Battle);
	}
	if (partyCompositionButton.IsClicked())
	{
		Library::DebugTools::DebugLog("Party Composition Button Clicked");
		
		sceneManager.ChangeScene(SceneType::PartySelect);
	}
		
}
void HomeScene::Draw()
{
	
	background.Draw();
	startButton.Draw();
	partyCompositionButton.Draw();
	
	
}
void HomeScene::Finalize() 
{
	background.Finalize();
	startButton.Finalize();
	partyCompositionButton.Finalize();	
}