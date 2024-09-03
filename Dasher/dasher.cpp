#include "raylib.h"

struct AnimData
{
    Rectangle rec;
    Vector2 position;
    Vector2 frame;
    float updateTime;
    float runningTime;
};

bool CheckIfThePlayerIsInGround(AnimData playerAnimData, int windowsDimensions)
{
    return playerAnimData.position.y >= windowsDimensions * 0.9 - playerAnimData.rec.height;
}
AnimData updateAnimationData(AnimData animData, float dt, int rows, int cols)
{
    animData.runningTime += dt;
    if (animData.runningTime >= animData.updateTime)
    {
        animData.runningTime = 0.0f;
        animData.frame.x++;
        animData.rec.x = animData.frame.x * animData.rec.width;
        if (animData.frame.x > cols)
        {
            animData.frame.x = 0;
            if (rows == 0)
            {
                animData.frame.y = 0;
            }
            else
            {
                animData.frame.y++;
                animData.rec.y = animData.frame.y * animData.rec.height;
                if (animData.frame.y > rows)
                {
                    animData.frame.y = 0;
                }
            }
        }
    }
    return animData;
}

int main()
{
    int windowsDimensions[2] = {800, 450};

    InitWindow(windowsDimensions[0], windowsDimensions[1], "Dasher");

    float positionY = windowsDimensions[1] * 0.9;

    bool isPlaying = true;
    bool isWin = false;
    bool isLose = false;

    Texture2D player = LoadTexture("Assets/textures/scarfy.png");
    Texture2D enemy = LoadTexture("Assets/textures/12_nebula_spritesheet.png");
    Texture2D bg = LoadTexture("Assets/textures/far-buildings.png");
    Texture2D middground = LoadTexture("Assets/textures/back-buildings.png");
    Texture2D fg = LoadTexture("Assets/textures/foreground.png");

    // bg variables
    float bgx = 0.0f;
    float middgroundx = 0.0f;
    float fgx = 0.0f;

    // rules of game
    // int maxJumpHeight = 700;
    const int gravity{1000};
    bool isInAir = false;
    int jumpVelocity = -600;

    // Animation variables Enemy

    // initial position of the rectangle
    // graphics
    // Player
    int velocityY = 0;
    AnimData playerAnimData;
    playerAnimData.frame = {0, 0};
    playerAnimData.rec.width = player.width / 6;
    playerAnimData.rec.height = player.height;
    playerAnimData.rec.x = playerAnimData.frame.x * playerAnimData.rec.width;
    playerAnimData.rec.y = 0;
    const float lineOfGround = positionY - playerAnimData.rec.height;
    playerAnimData.position = {windowsDimensions[0] / 2 - playerAnimData.rec.width / 2, lineOfGround};
    playerAnimData.updateTime = 1.0f / 12.0f;
    playerAnimData.runningTime = 0.0f;

    // Enemy
    int enemyVelocityX = -200;

    // Enemies
    const int enemySize = 5;
    AnimData enemies[enemySize];
    for (int i = 0; i < enemySize; i++)
    {
        enemies[i].frame = {0, 0};
        enemies[i].rec.width = enemy.width / 8;
        enemies[i].rec.height = enemy.height / 8;
        enemies[i].rec.x = enemies[i].frame.x * enemies[i].rec.width;
        enemies[i].rec.y = enemies[i].frame.y * enemies[i].rec.height;
        const float enemyLineOfGround = positionY - enemies[i].rec.height;
        enemies[i].position = {windowsDimensions[0] - enemies[i].rec.width + i * 600, enemyLineOfGround};
        enemies[i].updateTime = 1.0f / 24.0f;
        enemies[i].runningTime = 0.0f;
    }

    float finalLine{enemies[enemySize - 1].position.x + enemies[enemySize - 1].rec.width};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Apply deltaTime
        float dt{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // Draw background
        bgx -= 20.0f * dt;
        int bgWidth = -bg.width * 3;
        if (bgx <= bgWidth)
        {
            bgx = 0.0f;
        }

        Vector2 bgPos{bgx, -200.0f};
        DrawTextureEx(bg, bgPos, 0.0f, 3.5f, WHITE);

        // Draw ground second time
        DrawTextureEx(bg, {bgPos.x + bg.width * 3, bgPos.y}, 0.0f, 3.5f, WHITE);

        // Draw middground
        middgroundx -= 100.0f * dt;
        int middgroundWidth = -middground.width * 3;
        if (middgroundx <= middgroundWidth)
        {
            middgroundx = 0.0f;
        }
        DrawTextureEx(middground, {middgroundx, (float)-middground.height + 70}, 0.0f, 3.0f, WHITE);
        DrawTextureEx(middground, {middgroundx + middground.width * 3, (float)-middground.height + 70}, 0.0f, 3.0f, WHITE);
        DrawTextureEx(middground, {middgroundx + middground.width * 6, (float)-middground.height + 70}, 0.0f, 3.0f, WHITE);

        // draw foreground
        fgx -= 220.0f * dt;
        int fgWidth = -fg.width * 3;
        if (fgx <= fgWidth)
        {
            fgx = 0.0f;
        }
        DrawTextureEx(fg, {fgx, (float)-fg.height + 70}, 0.0f, 3.0f, WHITE);
        DrawTextureEx(fg, {fgx + fg.width * 3, (float)-fg.height + 70}, 0.0f, 3.0f, WHITE);
        DrawTextureEx(fg, {fgx + fg.width * 6, (float)-fg.height + 70}, 0.0f, 3.0f, WHITE);

        // check if player is on the ground
        if (CheckIfThePlayerIsInGround(playerAnimData, windowsDimensions[1]))
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

        playerAnimData.position.y += velocityY * dt;

        // Animation Enemy
        // update animation of all enemies en x and y
        for (int i = 0; i < enemySize; i++)
        {
            enemies[i].runningTime += dt;
            if (enemies[i].runningTime >= enemies[i].updateTime)
            {
                enemies[i].runningTime = 0.0f;
                enemies[i].frame.x++;
                if (enemies[i].frame.x > 7)
                {
                    enemies[i].frame.x = 0;
                    enemies[i].frame.y++;
                    if (enemies[i].frame.y > 7)
                    {
                        enemies[i].frame.y = 0;
                    }
                }
            }
        }

        // Animation Player
        if (!isInAir)
        {
            playerAnimData = updateAnimationData(playerAnimData, dt, 0, 5);
        }

        playerAnimData.rec.x = playerAnimData.frame.x * playerAnimData.rec.width;

        // Draw objects

        // player
        if (isPlaying)
        {
            DrawTextureRec(player, playerAnimData.rec, playerAnimData.position, WHITE);
        }

        // enemy
        // Drawon and update enemies all enemies from array
        for (int i = 0; i < enemySize; i++)
        {
            enemies[i].position.x += enemyVelocityX * dt;
            enemies[i] = updateAnimationData(enemies[i], dt, 7, 7);
            if (isPlaying)
            {
                DrawTextureRec(enemy, enemies[i].rec, enemies[i].position, WHITE);
            }
        }

        // Conditions
        finalLine += enemyVelocityX * dt;

        // detect if the player is dead
        for (AnimData enemy : enemies)
        {
            float pad{20};
            if (CheckCollisionRecs({playerAnimData.position.x + pad, playerAnimData.position.y + pad, playerAnimData.rec.width - 2 * pad, playerAnimData.rec.height - 2 * pad},
                                   {enemy.position.x + pad, enemy.position.y + pad, enemy.rec.width - 2 * pad, enemy.rec.height - 2 * pad}))
            {
                isPlaying = false;
                isLose = true;
            }
            else if (finalLine < enemySize + 1 * enemy.rec.width + enemy.rec.width * 2)
            {
                isPlaying = false;
                isWin = true;
            }
        }

        if (!isPlaying)
        {
            if (isWin)
            {
                DrawText("You Win", windowsDimensions[0] / 2 - 50, windowsDimensions[1] / 2, 20, GREEN);
                DrawText("Press R to restart", windowsDimensions[0] / 2 - 50, windowsDimensions[1] / 2 + 20, 20, GREEN);
            }
            else if (isLose)
            {
                DrawText("Game Over", windowsDimensions[0] / 2 - 50, windowsDimensions[1] / 2, 20, RED);
                DrawText("Press R to restart", windowsDimensions[0] / 2 - 50, windowsDimensions[1] / 2 + 20, 20, RED);
            }
            if (IsKeyPressed(KEY_R))
            {
                playerAnimData.position = {windowsDimensions[0] / 2 - playerAnimData.rec.width / 2, lineOfGround};
                for (int i = 0; i < enemySize; i++)
                {
                    enemies[i].position = {windowsDimensions[0] - enemies[i].rec.width + i * 600, positionY - enemies[i].rec.height};
                }
                finalLine = enemies[enemySize - 1].position.x + enemies[enemySize - 1].rec.width;
                isPlaying = true;
                isWin = false;
                isLose = false;
            }
        }

        // End Drawing
        EndDrawing();
    }
    UnloadTexture(player);
    UnloadTexture(enemy);
    UnloadTexture(bg);
    UnloadTexture(middground);
    UnloadTexture(fg);
    CloseWindow();
    return 0;
}