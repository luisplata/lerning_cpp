#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 playerPosition);
    void finishGame() { UnloadTexture(texture); }
    Rectangle getCollisionRec(Vector2 playerPosition);

private:
    Texture2D texture{};
    Vector2 wordPosition{};
    float scale{4.0f};
};