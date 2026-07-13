#pragma once
//PlayerAction“à‚Ìó‘Ô‚ğŠÇ—‚·‚é—ñ‹“Œ^
enum class ActionState
{
    None,
    Aim,
    Move,
    End
};

class EnemyActionManager
{
public:
    void UpdateAction();
    void SetActionState(ActionState state);

    ActionState currentActionState;

};