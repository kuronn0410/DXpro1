#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"
#include "UI/Button/Button.h"
class HomeScene : public IScene
{
public:
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	Background background;
	Button stageSelectButton;
	Button partyCompositionButton;
};