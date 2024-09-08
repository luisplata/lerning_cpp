#include "PowerUpSideAttack.h"

PowerUpSideAttack::PowerUpSideAttack(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius, std::vector<ICollisionWithBullet *> &enemies) : PowerUp(pos, idle, run, type), distance(radius), enemies(enemies)
{
}

PowerUpSideAttack::~PowerUpSideAttack()
{
}

void PowerUpSideAttack::Render()
{
    PowerUp::Render();
}

void PowerUpSideAttack::TickFrame(float deltaTime)
{

    // Incremento del tiempo
    time += deltaTime;

    // Obtener la posición del Player
    Vector2 centerOfScreen = {static_cast<float>(Globals::screenWidth / 2), static_cast<float>(Globals::screenHeight / 2)};

    // Calcular la nueva posición del PowerUp en el eje X usando una función seno
    float newX = centerOfScreen.x + distance * sin(frequency * time);

    // Mantener la posición Y constante
    float newY = centerOfScreen.y;

    wordPosition = {newX, newY};

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
