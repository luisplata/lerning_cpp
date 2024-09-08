#include "Map.h"
#include "Globals.h"
#include "raylib.h"
#include "Player.h"

Map::Map(Vector2 pos, Texture2D idle, Texture2D run, Player *player) : ObjectInScreen(idle, run), player(player)
{
    wordPosition = pos;
    texture = idle;
    scale = 5.f;
}

Map::~Map()
{
}

Vector2 Map::getScreenPosition()
{
    return Vector2Scale(player->wordPosition, -1);
}

void Map::Render()
{
    DrawTextureEx(texture, getScreenPosition(), 0, Globals::globalScale * scale, WHITE);
}

void Map::TickFrame(float deltaTime)
{
}
