#include "Scene/HomeScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"
#include "DebugTools/Debug.h"

extern SceneManager sceneManager;

bool HomeScene::Initialize() 
{
	background.Initialize("Assets\\Textures\\Home.png");
	stageSelectButton.Initialize(
		g_device,
		"Assets\\Textures\\StageSelectButton.png",
		(g_windowWidth - 200.0f) / 2.0f, 
		g_windowHeight * 0.7f,          
		200.0f,                         
		100.0f                        
	);

	partyCompositionButton.Initialize(
		g_device,
		"Assets\\Textures\\PartyComposition.png",
		(g_windowWidth - 200.0f) / 2.0f -80.0f, 
		g_windowHeight * 0.72f,        
		80.0f,                        
		80.0f                       
	);

	
	return true;
}
void HomeScene::Update()
{
	stageSelectButton.Update();
	partyCompositionButton.Update();
	if (stageSelectButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::StageSelect);
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
	stageSelectButton.Draw();
	partyCompositionButton.Draw();
	
	
}
void HomeScene::Finalize() 
{
	background.Finalize();
	stageSelectButton.Finalize();
	partyCompositionButton.Finalize();	
}