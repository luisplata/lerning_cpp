#ifndef BASECHARACTER_H
#define BASECHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();

    Rectangle getCollisionRec();

    void undoMovement();

    void finishGame();

    Vector2 getWordPosition() { return wordPosition; }

    virtual void TickFrame(float deltaTime);

    virtual Vector2 getScreenPosition() = 0;

protected:
    Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
    Texture2D texture = idle;
    Vector2 wordPosition{};
    Vector2 wordPositionLastFrame{};
    float playerDirection = 1.0f; // 1: right, -1: left
    int currentFrame = 0;
    float framesCounter = 0;
    const int maxFrames = 6;
    const float framesSpeed = 1 / 12.0f;
    float speed = 4.0f;
    float width;
    float height;
    float scale{4.0f};
    Vector2 velocity{};

private:
};

#endif