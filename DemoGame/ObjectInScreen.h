#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "raymath.h"
class ObjectInScreen
{
    // this player have a information to move
public:
    Vector2 screenPosition;
    Vector2 wordPosition;
    Vector2 wordPositionLastFrame;
    Vector2 velocity;
    float speed{100.0f};
    int level{1};
    float health{100.0f};
    float damage{10.0f};
    ObjectInScreen();
    virtual Vector2 getScreenPosition() = 0;
    virtual Vector2 GetWorldPosition() { return wordPosition; }
    Texture2D textureToRender;
    virtual void undoMovement();
};

#endif