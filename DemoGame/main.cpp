#include "raylib.h"
#include "GameState.h"
#include "Globals.h"
#include "PerySystem.h"
#include <string>
#include "System_Input.h"

int main()
{
    const int screenWidth = Globals::screenWidth;
    const int screenHeight = Globals::screenHeight;
    InitWindow(screenWidth, screenHeight, "Demo Game");

    // Start systems of game
    PerySystem perySystem{};

    GameState gameState{screenWidth, screenHeight, &perySystem};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        float dt{GetFrameTime()};
        // Tick systems of game
        perySystem.Tick(dt);
        // Update game state
        gameState.Update(dt);
        EndDrawing();
    }
    CloseWindow();
}