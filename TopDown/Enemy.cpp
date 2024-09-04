#include "Enemy.h"
#include "raymath.h"
#include "raylib.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run) : wordPosition(pos), texture(idle), idle(idle), run(run)
{
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
}
void Enemy::TickFrame(float deltaTime)
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

    Rectangle source{currentFrame * width, 0, playerDirection * width, height};
    Rectangle dest{screenPosition.x, screenPosition.y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0, WHITE);
}

Rectangle Enemy::getCollisionRec()
{
    return Rectangle{screenPosition.x, screenPosition.y, scale * width, scale * height};
}

void Enemy::undoMovement()
{
    wordPosition = wordPositionLastFrame;
}

void Enemy::finishGame()
{
    UnloadTexture(idle);
    UnloadTexture(run);
}
