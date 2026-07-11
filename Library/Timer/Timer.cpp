#include "Timer.h"


float currentTime = 0.0f;
float endTime = 0.0f;
    
void Timer::Start(float seconds)
{
    currentTime = 0.0f;
    endTime = seconds;
}

void Timer::Update(float deltaTime)
{
    currentTime  += deltaTime;
}

bool Timer::IsFinished() const
{
    return currentTime >= endTime;
}
