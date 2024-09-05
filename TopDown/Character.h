#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int width, int height);
    virtual void TickFrame(float deltaTime) override;
    virtual Vector2 getScreenPosition() override;

    private:
    int windowWidth;
    int windowHeight;
};
#endif