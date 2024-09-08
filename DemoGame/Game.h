#ifndef GAME_H
#define GAME_H

#include "IState.h"
#include "Player.h"
#include "Map.h"
#include "PerySystem.h"

class Game : public IState
{
private:
public:
    Game(Player *player, Map *map, PerySystem *perySystem);
    ~Game();
    void Update(float dt) override;
    virtual void Render() override;
    virtual void OnEnter() override;
    Player *player;
    Map *map;
    PerySystem *perySystem;

protected:
private:
};
#endif