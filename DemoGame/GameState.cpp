#include "GameState.h"
#include "Globals.h"
#include "PerySystem.h"

int GameState::currentGameState = 0;

GameState::GameState(int windowsWidth, int windowsHeight, PerySystem *perySystem) : windowsWidth(windowsWidth), windowsHeight(windowsHeight), perySystem(perySystem)
{
    states[GameStateEnum::MainMenu] = new MainMenu(this, perySystem);
    states[GameStateEnum::Game] = new Game(this, perySystem);
    currentState = states[GameStateEnum::MainMenu];
    setState(GameStateEnum::MainMenu);
}

void GameState::Update(float dt)
{
    currentState->Update(dt);
}

void GameState::setState(GameStateEnum nextState)
{
    if (currentStateEnum == nextState)
        return;
    currentStateEnum = nextState;
    currentState->OnExit();
    currentState = states[currentStateEnum];
    currentState->OnEnter();
}

GameState::~GameState()
{
    // delete mainMenu;
}
