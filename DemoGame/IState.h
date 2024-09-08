#ifndef ISTATE_H
#define ISTATE_H
#include "GameStateEnum.h"
class IState
{
private:
    /* data */
public:
    IState() = default;
    ~IState() = default;
    virtual void OnEnter();
    virtual void OnExit();
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    bool isChangeState() const { return changeState; }
    bool changeState{false};
    GameStateEnum nextState{GameStateEnum::Undefined};
};
#endif