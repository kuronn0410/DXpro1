#pragma once
#include "Game/Enemy/EnemyType.h"
#include "Game/StartPos.h"
#include <vector>

struct StageEnemyEntry
{
    EnemyType type;

    float hpMultiplier;
    float atkMultiplier;
    float spdMultiplier;

    std::vector<StartPos> positions;
};