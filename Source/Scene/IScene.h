#pragma once
class IScene
{
public:
    virtual ~IScene() = default;

    virtual bool Initialize() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Finalize() = 0;
};