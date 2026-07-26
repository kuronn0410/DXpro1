#pragma once
#include "Scene/IScene.h"
class StageSelectScene : public IScene
{
public:
    bool Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;
private:

};