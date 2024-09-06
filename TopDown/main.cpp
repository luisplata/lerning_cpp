#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

int main()
{
    int windowSize[2] = {384, 384};
    InitWindow(windowSize[0], windowSize[1], "Top Down Game");
    SetTargetFPS(60);

    Texture2D map = LoadTexture("assets/nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPos = {0, 0};

    const float mapScale = 4.0f;

    // player
    Character player{windowSize[0], windowSize[1], LoadTexture("Assets/characters/knight_idle_spritesheet.png"), LoadTexture("Assets/characters/knight_run_spritesheet.png")};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("Assets/nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("Assets/nature_tileset/Rock.png")}};

    // enemy
    Enemy goblin{Vector2{200.f, 200.f},
                 LoadTexture("Assets/characters/goblin_idle_spritesheet.png"),
                 LoadTexture("Assets/characters/goblin_run_spritesheet.png")};

    goblin.setTarget(&player);

    // creating more enemies
    int numEnemies = 5;
    Enemy *enemies[numEnemies];
    for (int i = 0; i < numEnemies; i++)
    {
        enemies[i] = new Enemy{Vector2{800.f, 800.f},
                               LoadTexture("Assets/characters/slime_idle_spritesheet.png"),
                               LoadTexture("Assets/characters/slime_run_spritesheet.png")};
        enemies[i]->setTarget(&player);
    }

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

        // Condition to check if the player is dead
        if (player.getHealth() <= 0)
        {
            DrawText("Game Over", windowSize[0] / 2 - 50, windowSize[1] / 2, 20, RED);
            EndDrawing();
            continue;
        }
        else
        {
            std::string health = "Health: ";
            health.append(std::to_string(player.getHealth()), 0, 5);
            DrawText(health.c_str(), 10, 10, 20, RED);
        }

        // Draw player
        player.TickFrame(deltaTime);
        // Draw enemy
        goblin.TickFrame(deltaTime);

        // Draw more enemies
        for( Enemy* enemy : enemies)
        {
            enemy->TickFrame(deltaTime);
        }

        // Collision detection with map
        if (
            player.getWordPosition().x < 0 ||
            player.getWordPosition().y < 0 ||
            player.getWordPosition().x + windowSize[0] > map.width * mapScale ||
            player.getWordPosition().y + windowSize[1] > map.height * mapScale)
        {
            player.undoMovement();
        }

        // Collision detection with enemy and attack
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            if (CheckCollisionRecs(player.getWeaponCollisionRec(), goblin.getCollisionRec()))
            {
                goblin.setIsDead(true);
            }
            for (int i = 0; i < numEnemies; i++)
            {
                if (CheckCollisionRecs(player.getWeaponCollisionRec(), enemies[i]->getCollisionRec()))
                {
                    enemies[i]->setIsDead(true);
                }
            }
        }
        // Collision detection with props
        for (Prop prop : props)
        {
            if (CheckCollisionRecs(player.getCollisionRec(), prop.getCollisionRec(player.getWordPosition())))
            {
                player.undoMovement();
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    player.finishGame();
    goblin.finishGame();
    for (int i = 0; i < numEnemies; i++)
    {
        enemies[i]->finishGame();
    }
    for (Prop prop : props)
    {
        prop.finishGame();
    }
    CloseWindow();
}