#ifndef ENEMY_H
#define ENEMY_H
#include "ICollisionWithBullet.h"
#include "ObjectInScreen.h"
#include "raylib.h"
#include "Globals.h"

class Enemy : public ICollisionWithBullet, public ObjectInScreen
{
private:
    /* data */
public:
    Enemy(Texture2D idle, Texture2D run, Vector2 wordPosition, ObjectInScreen *target);
    ~Enemy();
    virtual Rectangle getCollisionRec() override { return ObjectInScreen::getCollisionRec(); }
    virtual void takeDamage(float damage);
    virtual Vector2 getScreenPosition() override;
    virtual void TickFrame(float deltaTime);
    virtual void Render();
    Vector2 wordPosition{};
    ObjectInScreen *target;
    float health{100.0f};
    bool isDead{false};
    virtual bool IsDead() override { return isDead; }
};

#endif
