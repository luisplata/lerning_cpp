#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int width, int height, Texture2D idle, Texture2D run);
    virtual void TickFrame(float deltaTime) override;
    virtual Vector2 getScreenPosition() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
    float getHealth() const { return health; }
    void takeDamage(float damage);

private:
    int windowWidth;
    int windowHeight;
    Texture2D weapon{LoadTexture("Assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.0f};
};
#endif