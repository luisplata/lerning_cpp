#include "System_Render.h"
#include "System_Map.h"
#include "Globals.h"
#include "system_player.h"

System_Render::System_Render()
{
}

System_Render::~System_Render()
{
}

void System_Render::Update(float dt)
{
    // Render map
    DrawTextureEx(mapTexture, System_Map::map.wordPosition, 0.0f, Globals::globalScale * Globals::mapScale, WHITE);

    // Render enemies

    // Render player positioon is in the middle of the screen
    Vector2 playerPosition{GetScreenCenter()};
    playerPosition.x -= playerTexture.width / 2;
    playerPosition.y -= playerTexture.height / 2;

    DrawTextureEx(playerTexture, playerPosition, 0.0f, Globals::globalScale * Globals::playerScale, WHITE);
}
