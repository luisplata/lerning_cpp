#include "PowerUp.h"
#include "raymath.h"

PowerUp::PowerUp(Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type) : ObjectInScreen(idle, run), type(type)
{
    this->wordPosition = pos;
}

PowerUp::~PowerUp()
{
}

void PowerUp::Render()
{
    // Dibujar el PowerUp en la nueva posición
    Rectangle source = {0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    Rectangle dest = {wordPosition.x, wordPosition.y, static_cast<float>(texture.width * scale * Globals::globalScale), static_cast<float>(texture.height * scale * Globals::globalScale)};
    Vector2 origin = {0, 0};

    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}

void PowerUp::TickFrame(float deltaTime)
{
}
