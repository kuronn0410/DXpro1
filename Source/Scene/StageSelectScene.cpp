#include "Scene/StageSelectScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"
#include "DebugTools/Debug.h"
#include <string>


bool StageSelectScene::Initialize()
{
	
	bool result = enemyStatusInitializer.Initialize();

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


	stage1Button.Initialize(
		g_device,
		"Assets\\Textures\\Stege1Button.png",
		(g_windowWidth - 270.0f) / 2.0f, 
		g_windowHeight * 0.1f,          
		300.0f,                         
		120.0f                        
	);

	stage2Button.Initialize(
		g_device,
		"Assets\\Textures\\Stege2Button.png",
		(g_windowWidth - 270.0f) / 2.0f, 
		g_windowHeight * 0.4f,          
		300.0f,                         
		120.0f                        
	);

	return true;
}
void StageSelectScene::Update()
{
	startButton.Update();
	backSceneButton.Update();
	stage1Button.Update();
	stage2Button.Update();
	if (startButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Battle);
	}

	if (backSceneButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Home);
	}

	if(stage1Button.IsClicked())
	{
		enemyStatusInitializer.SetStageNum(1);
		Library::DebugTools::DebugLog("Stage 1 selected");
	}

	if(stage2Button.IsClicked())
	{
		enemyStatusInitializer.SetStageNum(2);
		Library::DebugTools::DebugLog("Stage 2 selected");
	}
}
void StageSelectScene::Draw()
{

	background.Draw();
	startButton.Draw();
	backSceneButton.Draw();
	stage1Button.Draw();
	stage2Button.Draw();
}
void StageSelectScene::Finalize()
{
	background.Finalize();
	startButton.Finalize();
	backSceneButton.Finalize();
	stage1Button.Finalize();
	stage2Button.Finalize();	
}