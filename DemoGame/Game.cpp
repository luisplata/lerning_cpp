#include "Game.h"
#include "raylib.h"
#include "raymath.h"
#include "Globals.h"
#include "GameStateEnum.h"

Game::Game(IGameState *gameState, PerySystem *perySystem) : gameState{gameState}, perySystem{perySystem}
{
}

Game::~Game()
{
}

void Game::OnEnter()
{
    perySystem->AddSystem(EnumSystemsAvailable::System_Input);
    perySystem->AddSystem(EnumSystemsAvailable::System_Player);
    perySystem->AddSystem(EnumSystemsAvailable::System_Render);
    perySystem->AddSystem(EnumSystemsAvailable::System_Map);
}

void Game::Update(float dt)
{
    // if key is pressed, go to main menu
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        gameState->setState(GameStateEnum::MainMenu);
    }
}

void Game::OnExit()
{
    perySystem->ClearSystems();
}
