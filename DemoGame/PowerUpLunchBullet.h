#ifndef POWERUP_LUNCH_BULLET_H
#define POWERUP_LUNCH_BULLET_H
#include "PowerUp.h"
#include <vector>
#include "Bullet.h"
#include "raylib.h"
#include "ICollisionWithBullet.h"
#include "Player.h"

class PowerUpLunchBullet : public PowerUp
{
public:
    PowerUpLunchBullet(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, std::vector<ICollisionWithBullet *> &enemies, Player *player);
    ~PowerUpLunchBullet();
    virtual void Render() override;
    virtual void TickFrame(float deltaTime) override;
    float timeToLunchBullet{0.0f};
    float timeToLunchBulletMax{1.0f};
    float bulletSpeed{100.0f};
    float bulletSize{0.5f};
    float bulletDamage{1000.0f};
    float bulletLifeTime{15.0f};
    Vector2 bulletDirection{0, 0};
    void LunchBullet();
    // vector of enemies
    std::vector<ICollisionWithBullet *> &enemies;
    std::vector<Bullet *> bullets;
    Player *player;
    Texture2D bulletTexture{LoadTexture("Assets/Powers/bullet.png")};
};

#endif
