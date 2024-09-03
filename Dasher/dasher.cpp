#include "raylib.h"
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Dasher");

    // rules of game
    // int maxJumpHeight = 700;
    const int gravity{1000};
    bool isInAir = false;
    int jumpVelocity = -600;

    //Animation variables
    int frame = 0;
    float updateTime {1.0f / 12.0f}; // 12 frames per second
    float runningTime{0.0f};

    // initial position of the rectangle
    // graphics
    // Player
    Texture2D player = LoadTexture("Assets/textures/scarfy.png");
    Rectangle playerRec;
    playerRec.width = player.width / 6;
    playerRec.height = player.height;
    playerRec.x = frame * playerRec.width;
    playerRec.y = 0;
    const float lineOfGround = screenHeight * 0.8 - playerRec.height;
    Vector2 playerPosition = {screenWidth / 2 - playerRec.width / 2, lineOfGround};
    int velocityY = 0;

    // Enemy
    Texture2D enemy = LoadTexture("Assets/textures/12_nebula_spritesheet.png");
    Rectangle enemyRec;
    enemyRec.width = enemy.width / 8;
    enemyRec.height = enemy.height / 8;
    enemyRec.x = 0;
    enemyRec.y = 0;



    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Apply deltaTime
        float dt{GetFrameTime()};

        // check if player is on the ground
        if (playerPosition.y >= screenHeight * 0.8 - playerRec.height)
        {
            velocityY = 0;
            isInAir = false;
        }
        else
        {
            velocityY += gravity * dt;
            isInAir = true;
        }

        // Inputs
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocityY += jumpVelocity;
        }

        playerPosition.y += velocityY * dt;

        // Animation
        runningTime += dt;
        if (runningTime >= updateTime)
        {
            runningTime = 0.0f;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
        }
        playerRec.x = frame * playerRec.width;

        // Draw objects

        // player
        DrawTextureRec(player, playerRec, playerPosition, WHITE);

        // End Drawing
        EndDrawing();
    }
    UnloadTexture(player);
    UnloadTexture(enemy);
    CloseWindow();
    return 0;
}