#include "PowerUpLunchBullet.h"
#include "raylib.h"

PowerUpLunchBullet::PowerUpLunchBullet(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, std::vector<ICollisionWithBullet *> &enemies, Player *player) : PowerUp(pos, idle, run, type), enemies(enemies), player(player)
{
}

PowerUpLunchBullet::~PowerUpLunchBullet()
{
}

void PowerUpLunchBullet::Render()
{
    DrawTexture(this->idle, this->wordPosition.x, this->wordPosition.y, WHITE);
    for (auto bullet : bullets)
    {
        bullet->Render();
    }
}

void PowerUpLunchBullet::TickFrame(float deltaTime)
{
    timeToLunchBullet += deltaTime;
    if (timeToLunchBullet >= timeToLunchBulletMax)
    {
        // crear direcion aleatoria
        bulletDirection = Vector2Normalize({(GetRandomValue(-100, 100) / 100.f), (GetRandomValue(-1, 1) / 100.f)}); // refactor to get the enemy farthest player
        LunchBullet();
        timeToLunchBullet = 0.0f;
    }

    // Obtener la posición del Player
    Vector2 centerOfScreen = {static_cast<float>(Globals::screenWidth / 2), static_cast<float>(Globals::screenHeight / 2)};

    // Calcular la nueva posición del PowerUp en el eje X usando una función seno
    float newX = centerOfScreen.x;

    // Mantener la posición Y constante
    float newY = centerOfScreen.y;

    wordPosition = {newX, newY};

    for (auto bullet : bullets)
    {
        bullet->TickFrame(deltaTime);
    }
}

void PowerUpLunchBullet::LunchBullet()
{
    Bullet *bullet = new Bullet(player->getWordPosition(), bulletTexture, bulletTexture, this->bulletDirection, enemies, player);
    bullet->speed = this->bulletSpeed;
    bullet->scale = this->bulletSize;
    bullet->setDamage(this->bulletDamage);
    bullet->setLifeTime(this->bulletLifeTime);
    bullets.push_back(bullet);
}
