#pragma once
#include "Scene/IScene.h"
#include "Graphics/background.h"    
class BattleScene : public IScene
{
public:
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:
	Background background;
};