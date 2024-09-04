#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight)
{
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
    screenPosition = {
        static_cast<float>(winWidth) / 2.0f - (scale * ((width) / 2.f)),
        static_cast<float>(winHeight) / 2.0f - (scale * (height / 2.f))};
}

void Character::TickFrame(float deltaTime)
{
    wordPositionLastFrame = wordPosition;

    Vector2 directionFromInput{0, 0};

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        directionFromInput.x += 1;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        directionFromInput.x -= 1;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        directionFromInput.y -= 1;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        directionFromInput.y += 1;

    // set player idle if no input
    texture = Vector2Length(directionFromInput) == 0.0 ? idle : run;

    if (Vector2Length(directionFromInput) != 0.0)
    {
        wordPosition = Vector2Add(wordPosition, Vector2Scale(Vector2Normalize(directionFromInput), speed));
        directionFromInput.x >= 0 ? playerDirection = 1.0f : playerDirection = -1.0f;
    }

    // Animation
    framesCounter += deltaTime;
    if (framesCounter >= framesSpeed)
    {
        framesCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= maxFrames)
            currentFrame = 0;
    }

    Rectangle source{currentFrame * width, 0, playerDirection * width, height};
    Rectangle dest{screenPosition.x, screenPosition.y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0, WHITE);
}

Rectangle Character::getCollisionRec()
{
    return Rectangle{screenPosition.x, screenPosition.y, scale * width, scale * height};
}

void Character::undoMovement()
{
    wordPosition = wordPositionLastFrame;
}

void Character::finishGame()
{
    UnloadTexture(idle);
    UnloadTexture(run);
}
