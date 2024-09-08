#ifndef POWERUPORBIT_H
#define POWERUPORBIT_H
#include "PowerUp.h"
#include <vector>
#include "raylib.h"
#include "Globals.h"
#include "ICollisionWithBullet.h"

class PowerUpOrbit : public PowerUp
{
public:
    PowerUpOrbit(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius, std::vector<ICollisionWithBullet *> &enemies);
    ~PowerUpOrbit();
    virtual void Render() override;
    virtual void TickFrame(float deltaTime) override;
    virtual Vector2 getScreenPosition() override { return screenPosition; }
    virtual Rectangle getCollisionRec() override;
    float angle{0.0f};
    float speed{0.1f};
    float radius{1.0f};
    std::vector<ICollisionWithBullet *> &enemies;
    float damage{1000.0f};
};

#endif
