#include "mainMenu.h"
#include "raylib.h"
#include "GameStateEnum.h"
#include "PerySystem.h"

MainMenu::MainMenu(IGameState *gameState, PerySystem *perySystem) : gameState(gameState), perySystem(perySystem)
{
}

void MainMenu::Update(float dt)
{

    DrawText("Press any key to start", GetScreenWidth() / 2 - MeasureText("Press any key to start", 20) / 2, GetScreenHeight() / 2, 20, RED);
    // if key is pressed, startGame = true;
    if (!startGame)
    {
        // if key is pressed, startGame = true;
        if (GetKeyPressed() != 0)
        {
            gameState->setState(GameStateEnum::Game);
        }
    }
}

void MainMenu::OnEnter()
{
    startGame = false;
    perySystem->AddSystem(EnumSystemsAvailable::System_Input);
}

void MainMenu::OnExit()
{
    perySystem->ClearSystems();
}
