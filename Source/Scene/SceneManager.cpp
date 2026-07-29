#include "Scene/SceneManager.h"

bool SceneManager::Initialize(SceneType initialSceneType)
{
	//currentSceneType = initialSceneType;
	switch (initialSceneType)
	{
	case SceneType::Home:
		currentScene = std::make_unique<HomeScene>(*this);
		break;
	case SceneType::PartySelect:
		currentScene = std::make_unique<PartySelectScene>(*this);
		break;
	case SceneType::StageSelect:
		currentScene = std::make_unique<StageSelectScene>(*this);
		break;
	case SceneType::Battle:
		currentScene = std::make_unique<BattleScene>(*this);
		break;
	case SceneType::Reward:
		currentScene = std::make_unique<RewardScene>(*this);
		break;
	default:
		break;
	}

	if (!currentScene)
	{
		return false;
	}

	return currentScene->Initialize();
}

void SceneManager::Update()
{
	
	//呼び出したシーンの更新処理をここに追加
	if (currentScene)
	{
		currentScene->Update();
	}

}

void SceneManager::Draw()
{
	//呼び出すシーンの描画処理をここに追加
	if (currentScene)
	{
		currentScene->Draw();
	}
}

void SceneManager::Finalize()
{
	//呼び出すシーンの終了処理をここに追加
	if (currentScene)
	{
		currentScene->Finalize();
		currentScene.reset();
	}

}

void SceneManager::ChangeScene(SceneType nextSceneType)
{
	if (currentScene)
	{
		currentScene->Finalize();
	}
	switch (nextSceneType)
	{
	case SceneType::Home:
		currentScene = std::make_unique<HomeScene>(*this);
		break;
	case SceneType::PartySelect:
		currentScene = std::make_unique<PartySelectScene>(*this);
		break;
	case SceneType::StageSelect:
		currentScene = std::make_unique<StageSelectScene>(*this);
		break;
	case SceneType::Battle:
		currentScene = std::make_unique<BattleScene>(*this);
		break;
	case SceneType::Reward:
		currentScene = std::make_unique<RewardScene>(*this); 
		break;
	default:
		break;		
	}

	if (currentScene)
	{
		currentScene->Initialize();
	}
}