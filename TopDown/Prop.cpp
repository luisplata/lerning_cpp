#include "Prop.h"
#include "raymath.h"
#include "raylib.h"

Prop::Prop(Vector2 pos, Texture2D tex) : wordPosition(pos), texture(tex)
{
}

void Prop::Render(Vector2 playerPosition)
{
    Vector2 screenPosition = Vector2Subtract(wordPosition, playerPosition);
    DrawTextureEx(texture, screenPosition, 0, scale, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 playerPosition)
{
    Vector2 screenPosition = Vector2Subtract(wordPosition, playerPosition);
    return Rectangle{screenPosition.x, screenPosition.y, texture.width * scale, texture.height * scale};
}
