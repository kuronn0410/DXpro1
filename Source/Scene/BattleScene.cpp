#include "Scene/BattleScene.h"
#include "Game/GameMain.h"



bool BattleScene::Initialize()
{
	enemyStatusInitializer.CreateEnemyStatuses();
	gameMain.Initialize();
	background.Initialize("Assets\\Textures\\Shiba.png");
	return true;
}
void BattleScene::Update()
{
		// Update logic for the Battle Scene
	gameMain.Update();
}
void BattleScene::Draw()
{
		// Draw the Battle Scene
	background.Draw();
	gameMain.Draw();
}
void BattleScene::Finalize()
{
	background.Finalize();
	gameMain.Finalize();
		// Clean up resources for the Battle Scene
}