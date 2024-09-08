#ifndef SYSTEM_PLAYER_H
#define SYSTEM_PLAYER_H
#include "ISystem.h"

class SystemPlayer : public ISystem
{
public:
    SystemPlayer();
    virtual void Update(float dt) override;
    
};

#endif