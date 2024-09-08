#ifndef MAP_H
#define MAP_H

#include "ObjectInScreen.h"
#include "Player.h"

class Map : public ObjectInScreen
{
private:
    /* data */
public:
    Map(Vector2 pos, Texture2D idle, Texture2D run, Player *player);
    ~Map();
    virtual Vector2 getScreenPosition() override;
    virtual void Render() override;
    Player *player;
    virtual void TickFrame(float deltaTime) override;
    
};

#endif