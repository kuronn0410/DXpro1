#pragma once
//1ƒ^[ƒ““à‚Ìó‘Ô‚ğŠÇ—‚·‚é—ñ‹“Œ^
enum class TurnState
{
    TurnStart,
    PlayerSelect,
    PlayerAction,
    EnemyAction,
    TurnEnd
};


class TurnManager
{
public:
    void SetTurnState(TurnState state);
    // ó‘Ô•ÏX
	const TurnState& GetTurnState() const;
    
   
private:
    TurnState currentTurnState;

};

