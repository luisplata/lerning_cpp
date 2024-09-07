#include "System_Map.h"
#include "Map.h"
#include "System_Player.h"
#include "raylib.h"
#include <string>

Map System_Map::map = Map();

System_Map::System_Map()
{
}

System_Map::~System_Map()
{
}

void System_Map::Update(float dt)
{
    DrawText("Map", 10, 10, 20, RED);
    map.wordPosition = Vector2Scale(SystemPlayer::player.wordPosition, -1.f);
}
