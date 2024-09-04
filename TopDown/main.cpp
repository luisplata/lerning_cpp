#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
    int windowSize[2] = {384, 384};
    InitWindow(windowSize[0], windowSize[1], "Top Down Game");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("assets/nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPos = {0, 0};

    const float mapScale = 4.0f;

    // player
    Character player{windowSize[0], windowSize[1]};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("assets/nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("assets/nature_tileset/Rock.png")}};

    // enemy
    Enemy goblin{Vector2{200.f, 200.f},
                 LoadTexture("assets/characters/goblin_idle_spritesheet.png"),
                 LoadTexture("assets/characters/goblin_run_spritesheet.png")};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        float deltaTime{GetFrameTime()};

        mapPos = Vector2Scale(player.getWordPosition(), -1);

        DrawTextureEx(map, mapPos, 0, mapScale, WHITE);

        // Draw props
        for (Prop prop : props)
        {
            prop.Render(player.getWordPosition());
        }

        player.TickFrame(deltaTime);

        // Collision detection with map
        if (
            player.getWordPosition().x < 0 ||
            player.getWordPosition().y < 0 ||
            player.getWordPosition().x + windowSize[0] > map.width * mapScale ||
            player.getWordPosition().y + windowSize[1] > map.height * mapScale)
        {
            player.undoMovement();
        }

        // Collision detection with props
        for (Prop prop : props)
        {
            if (CheckCollisionRecs(player.getCollisionRec(), prop.getCollisionRec(player.getWordPosition())))
            {
                player.undoMovement();
            }
        }

        // Draw enemy
        goblin.TickFrame(deltaTime);

        EndDrawing();
    }
    UnloadTexture(map);
    player.finishGame();
    for (Prop prop : props)
    {
        prop.finishGame();
    }
    CloseWindow();
}