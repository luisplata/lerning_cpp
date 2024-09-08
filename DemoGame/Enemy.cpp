#include "Enemy.h"

Enemy::Enemy(Texture2D idle, Texture2D run, Vector2 wordPosition, ObjectInScreen *target) : ObjectInScreen(idle, run), wordPosition(wordPosition), target(target)
{
    speed = 20.0f;
}

Enemy::~Enemy()
{
}

void Enemy::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
    {
        isDead = true;
    }
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(wordPosition, target->getWordPosition());
}

void Enemy::TickFrame(float deltaTime)
{
    if (isDead)
        return;
    wordPositionLastFrame = wordPosition;
    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());
    if (Vector2Length(velocity) <= 0)
    {
        // velocity = {};
    }
    // ObjectInScreen::TickFrame(deltaTime);
    if (Vector2Length(velocity) != 0.0)
    {
        wordPosition = Vector2Add(wordPosition, Vector2Scale(Vector2Normalize(velocity), speed * deltaTime));
        velocity.x > 0 ? playerDirection = 1.0f : playerDirection = -1.0f;
    }
}

void Enemy::Render()
{
    if (isDead)
        return;
    ObjectInScreen::Render();
}
