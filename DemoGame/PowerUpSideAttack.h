#ifndef POWERUPSIDEATTACK_H
#define POWERUPSIDEATTACK_H
#include "PowerUp.h"
#include <vector>
#include "raylib.h"
#include "Globals.h"
#include "ICollisionWithBullet.h"

class PowerUpSideAttack : public PowerUp
{
public:
    PowerUpSideAttack(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius, std::vector<ICollisionWithBullet *> &enemies);
    ~PowerUpSideAttack();
    virtual void Render() override;
    virtual void TickFrame(float deltaTime) override;
    float speed{100.f};
    float time{0.0f};
    float distance{200.0f}; // Amplitud de la oscilación
    float frequency{10.f};
    float damage{1000.0f};
    std::vector<ICollisionWithBullet *> &enemies;
};

#endif