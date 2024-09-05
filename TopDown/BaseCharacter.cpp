#include "BaseCharacter.h"
#include "raylib.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{getScreenPosition().x, getScreenPosition().y, scale * width, scale * height};
}

void BaseCharacter::undoMovement()
{
    wordPosition = wordPositionLastFrame;
}

void BaseCharacter::finishGame()
{
    UnloadTexture(idle);
    UnloadTexture(run);
}

void BaseCharacter::TickFrame(float deltaTime)
{
    wordPositionLastFrame = wordPosition;
    // Animation
    framesCounter += deltaTime;
    if (framesCounter >= framesSpeed)
    {
        framesCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= maxFrames)
            currentFrame = 0;
    }

    texture = Vector2Length(velocity) == 0.0 ? idle : run;

    if (Vector2Length(velocity) != 0.0)
    {
        wordPosition = Vector2Add(wordPosition, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x > 0 ? playerDirection = 1.0f : playerDirection = -1.0f;
    }

    velocity = {};

    Rectangle source{currentFrame * width, 0, playerDirection * width, height};
    Rectangle dest{getScreenPosition().x, getScreenPosition().y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0, WHITE);
}
