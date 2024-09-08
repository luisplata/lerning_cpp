#ifndef PLAYER_H
#define PLAYER_H
#include "ObjectInScreen.h"
#include <vector>
#include "PowerUp.h"
#include "IPlayer.h"
#include "PerySystem.h"
#include "ICollisionWithBullet.h"

class Player : public ObjectInScreen, public IPlayer, public ICollisionWithBullet
{
public:
    Player(Texture2D idle, Texture2D run);
    virtual Rectangle getCollisionRec() override;
    virtual void takeDamage(float damage) override;
    virtual void TickFrame(float deltaTime) override;
    virtual Vector2 getScreenPosition() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
    float getHealth() const { return health; }
    virtual void Render() override;
    std::vector<PowerUp *> powerUps;
    virtual bool IsDead() override { return health <= 0; }

private:
    Texture2D weapon{LoadTexture("Assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.0f};
};
#endif
