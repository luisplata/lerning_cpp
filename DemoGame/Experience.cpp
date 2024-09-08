#include "Experience.h"

Experience::Experience(Texture2D idle, Texture2D run) : ObjectInScreen(idle, run)
{
}

Experience::~Experience()
{
}

void Experience::Reset()
{
}

Vector2 Experience::getScreenPosition()
{
    return Vector2();
}

void Experience::TickFrame(float deltaTime)
{
    // Vector2 screenPosition = Vector2Subtract(wordPosition, playerPosition);
    // DrawTextureEx(texture, screenPosition, 0, scale, WHITE);
}
