#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
#include "Globals.h"
#include "ObjectInScreen.h"
#include "ICollisionWithBullet.h"
#include <vector>
#include "Player.h"

class Bullet : public ObjectInScreen
{
private:
    Vector2 direction{};
    std::vector<ICollisionWithBullet *> &enemies;
    Player *player;
    float damage{};
    float lifeTime{};
    bool isDead{false};

public:
    virtual Vector2 getScreenPosition() override;
    Bullet(Vector2 pos, Texture2D idle, Texture2D run, Vector2 direction, std::vector<ICollisionWithBullet *> &enemies, Player *player);
    ~Bullet();
    virtual void Render() override;
    virtual void TickFrame(float deltaTime) override;
    float getDamage() const { return damage; }
    float getLifeTime() const { return lifeTime; }
    void setLifeTime(float lifeTime) { this->lifeTime = lifeTime; }
    void setDamage(float damage) { this->damage = damage; }
    Vector2 screenPosition = {};
};

#endif