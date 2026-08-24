#include "Scene/TitleScene.h"
#include "DebugTools/Debug.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"


bool TitleScene::Initialize()
{

	background.Initialize("Assets/Textures/Title/TitleNormal.jpg");

	startButton.Initialize(
		g_device,
		"Assets/Textures/GameStartButton.png",
		(g_windowWidth - 200.0f) / 2.0f,
		g_windowHeight * 0.7f,
		200.0f,
		100.0f
	);
	return true;
}

void TitleScene::Update()
{

	startButton.Update();
	if (startButton.IsClicked())
	{
		sceneManager.ChangeScene(SceneType::Home);
	}

}


void TitleScene::Draw()
{
	background.Draw();
	startButton.Draw();
}

void TitleScene::Finalize()
{
	background.Finalize();
	startButton.Finalize();
}