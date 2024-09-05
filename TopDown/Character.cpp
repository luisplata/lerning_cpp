#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth), windowHeight(winHeight)
{
    width = static_cast<float>(texture.width) / maxFrames;
    height = static_cast<float>(texture.height);
}

Vector2 Character::getScreenPosition()
{
    return Vector2{
static_cast<float>(windowWidth) / 2.0f - (scale * ((width) / 2.f)),
        static_cast<float>(windowHeight) / 2.0f - (scale * (height / 2.f))
    };
}

void Character::TickFrame(float deltaTime)
{

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        velocity.y += 1;

    BaseCharacter::TickFrame(deltaTime);
}
