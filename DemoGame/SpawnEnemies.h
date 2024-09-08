#ifndef SPAWNENEMIES_H
#define SPAWNENEMIES_H
#include "ISystem.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

class SpawnEnemies : public ISystem
{
private:
    float timeToSpawn{0.0f};
    float timeToSpawnMax{10.0f};
    float countOfEnemies{20.0f};
    float radius{200.0f};
    std::vector<ICollisionWithBullet *> enemies;
    Player *player;

public:
    SpawnEnemies(float ratio, float radius, Player *player);
    ~SpawnEnemies();
    virtual void Update(float dt) override;
    std::vector<ICollisionWithBullet *> &getEnemies() { return enemies; }
    Texture2D idle{LoadTexture("Assets/Characters/Enemy_bat.png")};
};

#endif