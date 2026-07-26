#include "Scene/BattleScene.h"
#include "Game/GameMain.h"


bool BattleScene::Initialize()
{
	GameInitialize();
	background.Initialize("Assets\\Textures\\Shiba.png");
		// Initialize resources for the Battle Scene
	return true;
}
void BattleScene::Update()
{
		// Update logic for the Battle Scene
	GameUpdate();
}
void BattleScene::Draw()
{
		// Draw the Battle Scene
	background.Draw();
	GameDraw();
}
void BattleScene::Finalize()
{
	background.Finalize();
	GameFinalize();
		// Clean up resources for the Battle Scene
}