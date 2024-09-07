#ifndef SYSTEM_PLAYER_H
#define SYSTEM_PLAYER_H
#include "ISystem.h"
#include "raylib.h"
#include "raymath.h"
#include "Player.h"

class SystemPlayer : public ISystem
{
public:
    SystemPlayer();
    virtual void Update(float dt) override;
    static Player player;
};

#endif