#include "System_Player.h"
#include "System_Input.h"
#include "raylib.h"
#include "raymath.h"
#include <string>
#include "Globals.h"
#include "System_Map.h"

Player SystemPlayer::player = Player();

SystemPlayer::SystemPlayer()
{
}

void SystemPlayer::Update(float dt)
{
    player.wordPositionLastFrame = player.GetWorldPosition();

    player.velocity = Vector2Normalize(System_Input::velocity);

    player.wordPosition = Vector2Add(player.wordPosition, Vector2Scale(player.velocity, player.speed * dt));

    if (player.GetWorldPosition().x < 0.f ||
        player.GetWorldPosition().y < 0.f ||
        player.GetWorldPosition().x + Globals::screenWidth > System_Map::map.textureToRender.width * Globals::globalScale * Globals::mapScale ||
        player.GetWorldPosition().y + Globals::screenHeight > System_Map::map.textureToRender.height * Globals::globalScale * Globals::mapScale)
    {
        //player.undoMovement();
    }

    std::string str = "Player Position: " + std::to_string(player.wordPosition.x) + ", " + std::to_string(player.wordPosition.y);
    DrawText(str.c_str(), 10, 30, 20, RED);
}