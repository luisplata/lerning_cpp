#include "Bullet.h"

Vector2 Bullet::getScreenPosition()
{
    return screenPosition;
}

Bullet::Bullet(Vector2 pos, Texture2D idle, Texture2D run, Vector2 direction, std::vector<ICollisionWithBullet *> &enemies, Player *player) : ObjectInScreen(idle, run), direction(direction), enemies(enemies), player(player)
{
    // center of the screen
    wordPosition = Vector2Add(player->getScreenPosition(), player->getWordPosition());
    damage = 10.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Render()
{
    if (isDead)
        return;

    // Convertir la posición del mundo a la posición de la pantalla
    screenPosition = Vector2Subtract(this->wordPosition, player->getWordPosition());
    DrawTextureEx(run, screenPosition, 0, scale * Globals::globalScale, WHITE);
}

void Bullet::TickFrame(float deltaTime)
{
    if (isDead)
        return;
    // Mover el Bullet en la dirección que se le asignó

    wordPosition = Vector2Add(wordPosition, Vector2Scale(direction, speed * deltaTime));

    // Verificar si el Bullet esta fuera de tiempo
    lifeTime -= deltaTime;
    if (lifeTime <= 0)
    {
        isDead = true;
        return;
    }

    // Verificar colision con el player
    for (auto enemy : enemies)
    {
        if (enemy->IsDead())
            continue;

        // Dibujar el rectángulo de colisión
        DrawRectangleLines(getCollisionRec().x, getCollisionRec().y, getCollisionRec().width, getCollisionRec().height, RED);
        // Dibujar el rectángulo de colisión
        DrawRectangleLines(enemy->getCollisionRec().x, enemy->getCollisionRec().y, enemy->getCollisionRec().width, enemy->getCollisionRec().height, BLUE);
        if (CheckCollisionRecs(getCollisionRec(), enemy->getCollisionRec()))
        {
            enemy->takeDamage(damage);
            isDead = true;
            return;
        }
    }
}
