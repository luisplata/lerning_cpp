#include "PowerUpOrbit.h"

PowerUpOrbit::PowerUpOrbit(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius, std::vector<ICollisionWithBullet *> &enemies) : PowerUp(pos, idle, run, type), radius(radius), enemies(enemies)
{
}

PowerUpOrbit::~PowerUpOrbit()
{
}

void PowerUpOrbit::Render()
{
    PowerUp::Render();
}

void PowerUpOrbit::TickFrame(float deltaTime)
{

    // Centro de la pantalla
    float centerX = static_cast<float>(Globals::screenWidth / 2);
    float centerY = static_cast<float>(Globals::screenHeight / 2);

    // Incremento del ángulo
    angle += deltaTime; // Incrementa el ángulo con el tiempo

    // Calcular la nueva posición del PowerUp en la órbita
    float newX = centerX + radius * cos(angle);
    float newY = centerY + radius * sin(angle);

    wordPosition = {newX, newY};

    screenPosition = {wordPosition.x, wordPosition.y};
    PowerUp::TickFrame(deltaTime);

    // Verificar colision con el player
    for (auto enemy : enemies)
    {
        if (enemy->IsDead())
            continue;

        // Dibujar el rectángulo de colisión
        DrawRectangleLines(wordPosition.x, wordPosition.y, scale * width * Globals::globalScale, scale * height * Globals::globalScale, RED);
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

Rectangle PowerUpOrbit::getCollisionRec()
{
    Rectangle rec{getScreenPosition().x, getScreenPosition().y, scale * width * Globals::globalScale, scale * height * Globals::globalScale};
    return rec;
}
