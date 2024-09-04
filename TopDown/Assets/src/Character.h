#include "raylib.h"

class Character
{
public:
    Character(int width, int height);

    Vector2 getWordPosition() { return wordPosition; }

    void TickFrame(float deltaTime);

    Rectangle getCollisionRec();

    void undoMovement();

    void finishGame();

private:
    Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
    Texture2D texture = idle;
    Vector2 screenPosition{};
    Vector2 wordPosition{};
    Vector2 wordPositionLastFrame{};
    float playerDirection = 1.0f; // 1: right, -1: left
    int currentFrame = 0;
    float framesCounter = 0;
    const int maxFrames = 6;
    const float framesSpeed = 1 / 12.0f;
    const float speed = 4.0f;
    float width;
    float height;
    float scale{4.0f};
};