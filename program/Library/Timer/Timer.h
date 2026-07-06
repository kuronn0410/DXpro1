#pragma once

class Timer
{
    public:
        void Start(float seconds);
        void Update(float deltaTime);
        bool IsFinished() const;

    private:
        float currentTime = 0.0f;
        float endTime = 0.0f;
};