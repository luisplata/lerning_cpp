#include "Game.h"
#include "raylib.h"
#include "Globals.h"

Game::Game(Player *player, Map *map, PerySystem *perySystem) : player(player), map(map), perySystem(perySystem)
{
}

Game::~Game()
{
}

void Game::Update(float dt)
{
    // if key is pressed, go to main menu
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !isChangeState())
    {
        changeState = true;
        nextState = GameStateEnum::MainMenu;
    }
    // Update
    player->TickFrame(dt);
    map->TickFrame(dt);
    if (
        player->getWordPosition().x < 0 ||
        player->getWordPosition().y < 0 ||
        player->getWordPosition().x + Globals::screenWidth > map->width * map->scale * Globals::globalScale ||
        player->getWordPosition().y + Globals::screenHeight > map->height * map->scale * Globals::globalScale)
    {
        player->undoMovement();
    }
}

void Game::Render()
{
    // Reder
    map->Render();
    player->Render();
}

void Game::OnEnter()
{
    perySystem->AddSystem(EnumSystemsAvailable::System_EnemySpawner);
    IState::OnEnter();
}
