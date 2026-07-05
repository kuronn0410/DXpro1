#include "Time.h"
#include <Windows.h>

namespace Time
{
    float deltaTime = 0.0f;

    static DWORD oldTime = 0;

    void Init()
    {
        oldTime = GetTickCount();
    }

    void Update()
    {
        DWORD nowTime = GetTickCount();

        deltaTime = (nowTime - oldTime) / 1000.0f;

        oldTime = nowTime;
    }
}