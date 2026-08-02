#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"    
#include "UI/Button/Button.h"
#include "Game/GameMain.h"

class SceneManager;
class CharacterManager;
class EnemyStatusInitializer;

class BattleScene : public IScene
{
public:
	BattleScene(
		SceneManager& sceneManager, 
		CharacterManager& characterManager,
		EnemyStatusInitializer& enemyStatusInitializer):
		sceneManager(sceneManager), 
		characterManager(characterManager), 
		enemyStatusInitializer(enemyStatusInitializer),
		gameMain(characterManager, enemyStatusInitializer){};
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	SceneManager& sceneManager;
	CharacterManager& characterManager;
	EnemyStatusInitializer& enemyStatusInitializer;
	Background background;
	GameMain gameMain;

};