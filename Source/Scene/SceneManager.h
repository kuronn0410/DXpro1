#pragma once
#include "Scene/SceneType.h"
#include "Scene/IScene.h"
#include "Scene/HomeScene.h"
#include "Scene/StageSelectScene.h"
#include "Scene/BattleScene.h"
#include "Scene/PartySelectScene.h"
//#include "Scene/RewardScene.h"
#include <memory>


class SceneManager
{
public:
	bool Initialize(SceneType initialSceneType);
	void Update();
	void Draw();
	void Finalize();
	//切り替えるシーン
	void ChangeScene(SceneType nextSceneType);
private:
	//現在のシーンオブジェクト　unique_ptr <memory>
	std::unique_ptr<IScene> currentScene;

	//現在のシーンタイプ
	//SceneType currentSceneType;
	//シーンが切り替わったかどうかのフラグ
	bool isSceneChanged = false;
};