#include "Scene/PartySelectScene.h"
#include "Window/WindowState.h"
#include "Scene/SceneManager.h"
#include "DebugTools/Debug.h"

bool PartySelectScene::Initialize() 
{
    Library::DebugTools::DebugLog("PartySelectScene Initialize");
	background.Initialize("Assets\\Textures\\PartySelect.png");
    // Initialize resources for the Party Select Scene
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Initialize(
            g_device,
            "Assets\\Textures\\CharacterFrame.png",
            (g_windowWidth - 400.0f) / 2.0f + i * 100.0f, // Position buttons horizontally
            g_windowHeight * 0.7f,                        // Position buttons at 70% of the window height
            100.0f,                                       // Button width
            100.0f                                        // Button height
        );
    }
    backSceneButton.Initialize(
        g_device,
        "Assets\\Textures\\BackButton.png",
        (g_windowWidth) / 2.0f + 280.0f,  // Position the button at the top-left corner
        g_windowHeight * 0.03f,  // Position the button at the top-left corner
        30.0f, // Button width
        30.0f   // Button height
    );

	
	characterManager.Initialize();  
	characterCompositionUI.Initialize(characterManager);
   
    return true;
}

void PartySelectScene::Update() 
{
    // Update logic for the Party Select Scene
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Update();
    }
	backSceneButton.Update();

    if (backSceneButton.IsClicked())
    {
		sceneManager.ChangeScene(SceneType::Home);
    }
	characterCompositionUI.Update();
}

void PartySelectScene::Draw() 
{
    background.Draw();
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Draw();
    }
	backSceneButton.Draw();
	characterCompositionUI.Draw();
	
    // Draw the Party Select Scene
}

void PartySelectScene::Finalize() 
{
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Finalize();
    }
    characterCompositionUI.Finalize();
    characterManager.Finalize();
	background.Finalize();
	backSceneButton.Finalize();
    // Clean up resources for the Party Select Scene
}