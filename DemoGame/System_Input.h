#ifndef System_Input_h
#define System_Input_h
#include "ISystem.h"
#include "raylib.h"
class System_Input : public ISystem
{
public:
    System_Input();
    virtual void Update(float dt) override;
    static Vector2 velocity;

private:

protected:
};
#endif