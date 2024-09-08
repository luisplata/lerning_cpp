#include "raylib.h"
#include "Globals.h"
#include "PerySystem.h"
#include <string>
#include "System_Input.h"
#include "MainMenu.h"
#include "Game.h"
#include "Player.h"
#include "PowerUp.h"
#include "PowerUpOrbit.h"
#include "PowerUpSideAttack.h"
#include "PowerUpLunchBullet.h"
#include "Map.h"
#include "GameStateEnum.h"
#include <vector>
#include "SpawnEnemies.h"

IState *currentState{};
std::unordered_map<GameStateEnum, IState *> states;
GameStateEnum currentStateEnum{GameStateEnum::Undefined};

void setState(GameStateEnum nextState)
{
    if (currentStateEnum == nextState)
        return;
    currentStateEnum = nextState;
    currentState->OnExit();
    currentState = states[currentStateEnum];
    currentState->OnEnter();
}

Vector2 getScreenCenter()
{
    return Vector2{static_cast<float>(Globals::screenWidth / 2), static_cast<float>(Globals::screenHeight / 2)};
}

int main()
{
    const int screenWidth = Globals::screenWidth;
    const int screenHeight = Globals::screenHeight;
    InitWindow(screenWidth, screenHeight, "Demo Game");

    Player player{LoadTexture("Assets/Characters/Player.png"), LoadTexture("Assets/Characters/Player.png")};

    PerySystem perySystem{};
    // float ratio, float radius, Player *player
    SpawnEnemies *spawnEnemies = new SpawnEnemies{10.f, 200.0f, &player};
    perySystem.systemsAvailable[EnumSystemsAvailable::System_EnemySpawner] = spawnEnemies;
    perySystem.systems.push_back(perySystem.systemsAvailable[EnumSystemsAvailable::System_EnemySpawner]);

    perySystem.AddSystem(EnumSystemsAvailable::System_Input);

    std::vector<ICollisionWithBullet *> &enemies = static_cast<SpawnEnemies *>(perySystem.systemsAvailable[EnumSystemsAvailable::System_EnemySpawner])->getEnemies();

    // int width, int height, Texture2D idle, Texture2D run
    PowerUpOrbit powerUp1{{0, 0}, LoadTexture("Assets/Powers/power_1.png"), LoadTexture("Assets/Powers/power_1.png"), PowerUpType::PowerUp1, 100, enemies};           // Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius, std::vector<ICollisionWithBullet *> &enemies
    PowerUpSideAttack powerUp2{{0, 0}, LoadTexture("Assets/Powers/power_1.png"), LoadTexture("Assets/Powers/power_1.png"), PowerUpType::PowerUp2, 100, enemies};      // Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, float radius
    PowerUpLunchBullet powerUp3{{0, 0}, LoadTexture("Assets/Powers/power_1.png"), LoadTexture("Assets/Powers/power_1.png"), PowerUpType::PowerUp3, enemies, &player}; // Vector2 pos, Texture2D idle, Texture2D run, PowerUpType type, std::vector<ICollisionWithBullet *> &enemies, Player *player
    player.powerUps.push_back(&powerUp1);
    player.powerUps.push_back(&powerUp2);
    player.powerUps.push_back(&powerUp3);
    // Map(Vector2 pos, Texture2D idle, Texture2D run, Player *player);
    Map map{{0, 0}, LoadTexture("Assets/Map/map.png"), LoadTexture("Assets/Map/map.png"), &player};

    // PerySystem perySystem{};
    Game game{&player, &map, &perySystem};
    MainMenu mainMenu{};
    states[GameStateEnum::MainMenu] = &mainMenu;
    states[GameStateEnum::Game] = &game;

    currentState = states[GameStateEnum::MainMenu];
    setState(GameStateEnum::MainMenu);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        float dt{GetFrameTime()};
        currentState->Render();
        perySystem.Tick(dt);
        currentState->Update(dt);
        if (currentState->isChangeState())
        {
            setState(currentState->nextState);
        }
        EndDrawing();
    }
    CloseWindow();
}