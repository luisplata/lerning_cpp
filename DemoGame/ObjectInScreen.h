#ifndef OBJECT_SCREEN_H
#define OBJECT_SCREEN_H
#include "raylib.h"
#include "raymath.h"
#include "Globals.h"
#include <iostream>

class ObjectInScreen
{
public:
    ObjectInScreen(Texture2D idleAnim, Texture2D runAnim);

    virtual Vector2 getScreenPosition() = 0;

    virtual Rectangle getCollisionRec();

    void undoMovement();

    void finishGame();

    Vector2 getWordPosition() { return wordPosition; }

    virtual void TickFrame(float deltaTime);

    bool getIsDead() { return isDead; }

    void setIsDead(bool dead) { isDead = dead; }

    virtual void Render();
    Texture2D idle{};
    Texture2D run{};
    Texture2D texture = idle;
    Vector2 wordPosition{};
    Vector2 wordPositionLastFrame{};
    float playerDirection = 1.0f; // 1: right, -1: left
    int currentFrame = 0;
    float framesCounter = 0;
    const int maxFrames = 1;
    const float framesSpeed = 1 / 12.0f;
    float speed = 200.0f;
    float width;
    float height;
    float scale{1.0f};
    Vector2 velocity{};
    bool isDead{false};
};

#endif