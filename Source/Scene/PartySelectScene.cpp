#include "Scene/PartySelectScene.h"
#include "Window/WindowState.h"

bool PartySelectScene::Initialize() 
{
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
    return true;
}

void PartySelectScene::Update() 
{
    // Update logic for the Party Select Scene
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Update();
    }
}

void PartySelectScene::Draw() 
{
    background.Draw();
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Draw();
    }
	
    // Draw the Party Select Scene
}

void PartySelectScene::Finalize() 
{
    for (int i = 0; i < 4; ++i)
    {
        PartyButton[i].Finalize();
    }
	background.Finalize();
    // Clean up resources for the Party Select Scene
}