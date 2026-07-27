#pragma once
class RewardScene : public IScene
{
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
private:
	Background background;
	//Button rewardButton[3];
	Button backSceneButton;
};