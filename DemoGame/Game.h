#ifndef GAME_H
#define GAME_H

#include "IGameState.h"
#include "raylib.h"
#include "raymath.h"
#include "IState.h"
#include "PerySystem.h"

class Game : public IState
{
private:
    IGameState *gameState{};

public:
    Game(IGameState *gameState, PerySystem *perySystem);
    ~Game();
    void OnEnter() override;
    void Update(float dt) override;
    void OnExit() override;
    PerySystem* perySystem{};
};
#endif