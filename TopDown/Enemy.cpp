#include "Enemy.h"
#include "raymath.h"
#include "raylib.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run)
{
    wordPosition = pos;
    texture = idle;
    idle = idle;
    run = run;
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
    speed = 2.0f;
}

void Enemy::TickFrame(float deltaTime)
{
    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());
    BaseCharacter::TickFrame(deltaTime);
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(wordPosition, target->getWordPosition());
}
