#ifndef IGAMESTATE_H
#define IGAMESTATE_H
#include "GameStateEnum.h"
class IGameState
{
public:
    virtual ~IGameState() = default;
    virtual void setState(GameStateEnum nextState) = 0;
};
#endif