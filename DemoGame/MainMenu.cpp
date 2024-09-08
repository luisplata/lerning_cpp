#include "mainMenu.h"
#include "raylib.h"
#include "GameStateEnum.h"
#include "PerySystem.h"

MainMenu::MainMenu()
{
}

void MainMenu::Update(float dt)
{

    // if key is pressed, startGame = true;
    if (GetKeyPressed() != 0 && !isChangeState())
    {
        changeState = true;
        nextState = GameStateEnum::Game;
    }
}

void MainMenu::Render()
{
    DrawText("Press any key to start", GetScreenWidth() / 2 - MeasureText("Press any key to start", 20) / 2, GetScreenHeight() / 2, 20, RED);
}
