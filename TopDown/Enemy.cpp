#include "Enemy.h"
#include "raymath.h"
#include "raylib.h"

Enemy::Enemy(Vector2 pos, Texture2D idle, Texture2D run) : BaseCharacter(idle, run)
{
    wordPosition = pos;
    texture = idle;
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
    speed = 2.0f;
}

void Enemy::TickFrame(float deltaTime)
{
    if(getIsDead()) return;
    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());
    if(Vector2Length(velocity) < radius)
    {
        velocity = {};
    }
    BaseCharacter::TickFrame(deltaTime);
    if (CheckCollisionRecs(getCollisionRec(), target->getCollisionRec()))
    {
        target->takeDamage(damagePerSec * deltaTime);
    }
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(wordPosition, target->getWordPosition());
}
