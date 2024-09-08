#ifndef ICOLLISIONWITHBULLET_H
#define ICOLLISIONWITHBULLET_H

#include "raylib.h"
class ICollisionWithBullet
{
private:
    /* data */
public:
    virtual Rectangle getCollisionRec() = 0;
    virtual void takeDamage(float damage) = 0;
    virtual bool IsDead() = 0;
};

#endif