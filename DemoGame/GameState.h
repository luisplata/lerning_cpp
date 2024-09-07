#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "IRenderable.h"
#include "IUpdatable.h"
#include "MainMenu.h"
#include "IGameState.h"
#include "Game.h"
#include "IState.h"
#include <unordered_map>
#include "GameStateEnum.h"
#include "PerySystem.h"

class GameState : public IUpdatable, public IGameState
{
public:
    GameState(int windowsWidth, int windowsHeight, PerySystem* perySystem);
    void Update(float dt) override;
    virtual void setState(GameStateEnum nextState) override;
    virtual ~GameState() override;


protected:
private:
    int gameState{0};
    std::unordered_map<GameStateEnum, IState*> states;
    int windowsWidth{0};
    int windowsHeight{0};
    static int currentGameState;
    IState* currentState{};
    GameStateEnum currentStateEnum{GameStateEnum::Undefined};
    PerySystem* perySystem{};
};
#endif