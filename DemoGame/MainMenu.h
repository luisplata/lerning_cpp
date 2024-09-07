#ifndef MAINMENU_H
#define MAINMENU_H

#include "IRenderable.h"
#include "IUpdatable.h"
#include "IMainMenu.h"
#include "IGameState.h"
#include "IState.h"
#include "PerySystem.h"

class MainMenu : public IMainMenu, public IState
{
public:
    MainMenu(IGameState* gameState, PerySystem* perySystem);
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void Update(float dt) override;
    virtual bool isGameStarted() const { return startGame; }
private:
protected:
private:
    bool startGame{false};
    IGameState *gameState{};
    PerySystem* perySystem{};
};
#endif