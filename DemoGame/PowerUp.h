#ifndef POWERUP_H
#define POWERUP_H
#include "ObjectInScreen.h"
#include "IPlayer.h"

enum PowerUpType
{
    PowerUp1,
    PowerUp2,
    PowerUp3,
    PowerUp4,
};
class PowerUp : public ObjectInScreen
{
public:
    PowerUp(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type);
    ~PowerUp();
    PowerUpType type;
    virtual void Render() override;
    virtual void TickFrame(float deltaTime) override;
    Vector2 screenPosition = {};
    virtual Vector2 getScreenPosition() override { return wordPosition; }
};

#endif